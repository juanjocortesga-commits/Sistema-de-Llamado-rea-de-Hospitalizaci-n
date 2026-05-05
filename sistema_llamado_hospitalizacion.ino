#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <lvgl.h>
#include "Arduino_GFX_Library.h"
#include <PCF8574.h>

#include "ui.h"
#include "screens.h"

#define USBSerial Serial
// version 1.0
//===========
// PCF8574
//====================================================
PCF8574 pcf(0x20);

//====================================================
// PANTALLA
//====================================================
#define SCREEN_WIDTH   480
#define SCREEN_HEIGHT  480

//====================================================
// TOUCH GT911
//====================================================
#define TOUCH_SDA 15
#define TOUCH_SCL 7

#define GT911_ADDR_1 0x5D
#define GT911_ADDR_2 0x14

#define TOUCH_SWAP_XY   0
#define TOUCH_INVERT_X  1
#define TOUCH_INVERT_Y  1

uint8_t gt911Addr = GT911_ADDR_1;
uint16_t touchX = 0;
uint16_t touchY = 0;
bool touchDisponible = false;
bool pcfDisponible = false;
unsigned long ultimoReintentoTouch = 0;

//====================================================
// BUZZER
//====================================================
#define BUZZER_PCF_PIN 4
#define PCF_ESTADO_INICIAL 0xEF

//====================================================
// DISPLAY
//====================================================
Arduino_DataBus *bus = new Arduino_SWSPI(
    GFX_NOT_DEFINED, 42, 2, 1, GFX_NOT_DEFINED
);

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40, 39, 38, 41,
    46, 3, 8, 18, 17,
    14, 13, 12, 11, 10, 9,
    5, 45, 48, 47, 21,
    1, 10, 8, 50,
    1, 10, 8, 20
);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    rgbpanel,
    2,
    true,
    bus,
    GFX_NOT_DEFINED,
    st7701_type1_init_operations,
    sizeof(st7701_type1_init_operations)
);

//====================================================
// LVGL
//====================================================
static lv_disp_draw_buf_t draw_buf;
static lv_color_t draw_buf_1[SCREEN_WIDTH * 10];

//====================================================
// SISTEMA LLAMADOS
//====================================================
#define MAX_COLA 4

int cola[MAX_COLA];
int cantidad = 0;

bool llamadaActiva[5] = {false,false,false,false,false};
unsigned long inicioLlamado[5] = {0,0,0,0,0};
bool buzzerActivo = false;
bool estadoEstableBoton[4] = {HIGH, HIGH, HIGH, HIGH};
bool ultimaLecturaBoton[4] = {HIGH, HIGH, HIGH, HIGH};
unsigned long ultimoCambioBoton[4] = {0, 0, 0, 0};

#define DEBOUNCE_MS 40

//====================================================
// BUZZER
//====================================================
void encenderBuzzer()
{
    if (!pcfDisponible) return;
    if (buzzerActivo) return;

    pcf.write(BUZZER_PCF_PIN, HIGH);
    buzzerActivo = true;
}

void apagarBuzzer()
{
    if (!pcfDisponible) return;

    pcf.write(BUZZER_PCF_PIN, LOW);
    buzzerActivo = false;
}

//====================================================
// TOUCH
//====================================================
bool i2cDevicePresent(uint8_t addr)
{
    Wire.beginTransmission(addr);
    return Wire.endTransmission() == 0;
}

void scanI2CBus()
{
    USBSerial.println("Escaneo I2C:");

    for (uint8_t addr = 1; addr < 0x7F; addr++)
    {
        if (i2cDevicePresent(addr))
        {
            USBSerial.print(" - 0x");
            if (addr < 16) USBSerial.print('0');
            USBSerial.println(addr, HEX);
        }
    }
}

bool gt911Read(uint16_t reg, uint8_t *buffer, uint8_t len)
{
    Wire.beginTransmission(gt911Addr);
    Wire.write(reg >> 8);
    Wire.write(reg & 0xFF);

    if (Wire.endTransmission(false) != 0) return false;
    if (Wire.requestFrom(gt911Addr, len) != len) return false;

    for (uint8_t i = 0; i < len; i++) buffer[i] = Wire.read();
    return true;
}

bool gt911WriteByte(uint16_t reg, uint8_t value)
{
    Wire.beginTransmission(gt911Addr);
    Wire.write(reg >> 8);
    Wire.write(reg & 0xFF);
    Wire.write(value);
    return Wire.endTransmission() == 0;
}

bool initTouch()
{
    if (i2cDevicePresent(GT911_ADDR_1))
    {
        gt911Addr = GT911_ADDR_1;
        gt911WriteByte(0x814E, 0);
        USBSerial.println("Touch GT911 detectado en 0x5D");
        return true;
    }

    if (i2cDevicePresent(GT911_ADDR_2))
    {
        gt911Addr = GT911_ADDR_2;
        gt911WriteByte(0x814E, 0);
        USBSerial.println("Touch GT911 detectado en 0x14");
        return true;
    }

    USBSerial.println("Touch GT911 no detectado");
    return false;
}

bool readTouch()
{
    uint8_t status = 0;

    if (!gt911Read(0x814E, &status, 1)) return false;
    if ((status & 0x80) == 0) return false;

    uint8_t point[8];

    if (!gt911Read(0x8150, point, 8)) return false;

    touchX = point[0] | (point[1] << 8);
    touchY = point[2] | (point[3] << 8);

    gt911WriteByte(0x814E, 0);

    return true;
}

//====================================================
// LEDS
//====================================================
void actualizarLEDs()
{
    lv_led_off(objects.led_verde);
    lv_led_off(objects.led_amarillo);
    lv_led_off(objects.led_rojo);

    if (cantidad == 0)
        lv_led_on(objects.led_verde);
    else if (cantidad <= 2)
        lv_led_on(objects.led_amarillo);
    else
        lv_led_on(objects.led_rojo);
}

//====================================================
// TIEMPOS PRINCIPAL
//====================================================
void actualizarTiempos()
{
    for(int i = 0; i < cantidad; i++)
    {
        int hab = cola[i];
        int idx = hab - 300;

        unsigned long segundos = (millis() - inicioLlamado[idx]) / 1000;

        int min = segundos / 60;
        int seg = segundos % 60;

        char buffer[20];
        sprintf(buffer, "%02d:%02d", min, seg);

        if(i == 0) lv_label_set_text(objects.lbl_time1, buffer);
        if(i == 1) lv_label_set_text(objects.lbl_time2, buffer);
        if(i == 2) lv_label_set_text(objects.lbl_time3, buffer);
        if(i == 3) lv_label_set_text(objects.lbl_time4, buffer);
    }

    if(cantidad < 1) lv_label_set_text(objects.lbl_time1, "00:00");
    if(cantidad < 2) lv_label_set_text(objects.lbl_time2, "00:00");
    if(cantidad < 3) lv_label_set_text(objects.lbl_time3, "00:00");
    if(cantidad < 4) lv_label_set_text(objects.lbl_time4, "00:00");
}

//====================================================
// TIEMPOS HABITACIONES
//====================================================
void actualizarTiemposHabitaciones()
{
    for(int hab = 301; hab <= 304; hab++)
    {
        int idx = hab - 300;

        char buffer[25];

        if(llamadaActiva[idx])
        {
            unsigned long segundos = (millis() - inicioLlamado[idx]) / 1000;

            int min = segundos / 60;
            int seg = segundos % 60;

            sprintf(buffer, "TIEMPO: %02d:%02d", min, seg);
        }
        else
        {
            sprintf(buffer, "TIEMPO: 00:00");
        }

        if(hab == 301) lv_label_set_text(objects.lbl_tiempo_301, buffer);
        if(hab == 302) lv_label_set_text(objects.lbl_tiempo_302, buffer);
        if(hab == 303) lv_label_set_text(objects.lbl_tiempo_303, buffer);
        if(hab == 304) lv_label_set_text(objects.lbl_tiempo_304, buffer);
    }
}

//====================================================
// INTERFAZ
//====================================================
void actualizarHabitacion(int hab, const char *txt)
{
    if (hab == 301) lv_label_set_text(objects.lbl_llamado_301, txt);
    if (hab == 302) lv_label_set_text(objects.lbl_llamado_302, txt);
    if (hab == 303) lv_label_set_text(objects.lbl_llamado_303, txt);
    if (hab == 304) lv_label_set_text(objects.lbl_llamado_304, txt);
}

void actualizarPantalla()
{
    lv_label_set_text(objects.lbl_tarjeta1, cantidad > 0 ? String("HAB " + String(cola[0])).c_str() : "---------");
    lv_label_set_text(objects.lbl_tarjeta2, cantidad > 1 ? String("HAB " + String(cola[1])).c_str() : "---------");
    lv_label_set_text(objects.lbl_tarjeta3, cantidad > 2 ? String("HAB " + String(cola[2])).c_str() : "---------");
    lv_label_set_text(objects.lbl_tarjeta4, cantidad > 3 ? String("HAB " + String(cola[3])).c_str() : "---------");

    lv_label_set_text(objects.lbl_estado,
        cantidad > 0 ? "LLAMADOS ACTIVOS" : "SIN LLAMADOS");

    actualizarLEDs();
}

//====================================================
// LLAMADOS
//====================================================
void agregarLlamado(int hab)
{
    if (cantidad >= MAX_COLA) return;

    int idx = hab - 300;

    if (llamadaActiva[idx]) return;

    cola[cantidad] = hab;
    cantidad++;

    llamadaActiva[idx] = true;
    inicioLlamado[idx] = millis();

    actualizarHabitacion(hab, "LLAMADO: ACTIVO");

    encenderBuzzer();

    actualizarPantalla();
}

void atenderLlamado()
{
    apagarBuzzer();

    if (cantidad == 0) return;

    int hab = cola[0];
    int idx = hab - 300;

    llamadaActiva[idx] = false;

    actualizarHabitacion(hab, "LLAMADO: ATENDIDO");

    for (int i = 0; i < cantidad - 1; i++)
        cola[i] = cola[i + 1];

    cantidad--;

    actualizarPantalla();
}

//====================================================
// LVGL callbacks
//====================================================
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    gfx->draw16bitRGBBitmap(
        area->x1,
        area->y1,
        (uint16_t *)color_p,
        area->x2 - area->x1 + 1,
        area->y2 - area->y1 + 1
    );

    lv_disp_flush_ready(disp);
}

void my_touch_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static int lastX = 0;
    static int lastY = 0;

    if (touchDisponible && readTouch())
    {
        int x = touchX;
        int y = touchY;

#if TOUCH_SWAP_XY
        int t = x; x = y; y = t;
#endif
#if TOUCH_INVERT_X
        x = SCREEN_WIDTH - 1 - x;
#endif
#if TOUCH_INVERT_Y
        y = SCREEN_HEIGHT - 1 - y;
#endif

        x = constrain(x, 0, SCREEN_WIDTH - 1);
        y = constrain(y, 0, SCREEN_HEIGHT - 1);

        lastX = x;
        lastY = y;

        data->state = LV_INDEV_STATE_PR;
        data->point.x = x;
        data->point.y = y;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
        data->point.x = lastX;
        data->point.y = lastY;
    }
}

//====================================================
// SETUP
//====================================================
void setup()
{
    USBSerial.begin(115200);

    // I2C
    Wire.begin(TOUCH_SDA, TOUCH_SCL);
    Wire.setClock(100000);
    Wire.setTimeOut(20);

    // Config pantalla (IMPORTANTE)
    Wire.beginTransmission(0x24);
    Wire.write(0x02);
    Wire.write(0xFF);
    Wire.endTransmission();

    Wire.beginTransmission(0x24);
    Wire.write(0x03);
    Wire.write(0x3A);
    Wire.endTransmission();

    // 👉 PRIMERO TOUCH
    scanI2CBus();
    touchDisponible = initTouch();
    delay(50);

    // 👉 DESPUÉS PCF
    pcfDisponible = pcf.begin(PCF_ESTADO_INICIAL);
    USBSerial.println(pcfDisponible ? "PCF8574 detectado en 0x20" : "PCF8574 no detectado en 0x20");
    for(int i=0;i<4;i++)
    {
        pcf.write(i, HIGH);
    }
    pcf.write(BUZZER_PCF_PIN, LOW);

    // DISPLAY
    gfx->begin();
    gfx->fillScreen(BLACK);

    lv_init();

    lv_disp_draw_buf_init(&draw_buf, draw_buf_1, NULL, SCREEN_WIDTH * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = SCREEN_WIDTH;
    disp_drv.ver_res = SCREEN_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;

    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);

    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touch_read;

    lv_indev_drv_register(&indev_drv);

    ui_init();

    lv_obj_add_event_cb(objects.btn_atender, [](lv_event_t *e){ atenderLlamado(); }, LV_EVENT_CLICKED, NULL);

    actualizarPantalla();
    actualizarTiempos();
    actualizarTiemposHabitaciones();

    USBSerial.println("Sistema listo");
}

//====================================================
// LOOP
//====================================================
void loop()
{
    static uint32_t lastTick = millis();
    uint32_t now = millis();

    lv_tick_inc(now - lastTick);
    lastTick = now;

    if (!touchDisponible && millis() - ultimoReintentoTouch >= 1000)
    {
        ultimoReintentoTouch = millis();
        touchDisponible = initTouch();
    }

    if (pcfDisponible)
    {
        uint8_t estadoPcf = pcf.read8();
        int errorPcf = pcf.lastError();

        if (errorPcf != PCF8574_OK)
        {
            USBSerial.print("Error I2C PCF8574: ");
            USBSerial.println(errorPcf);
        }

        for(int i=0;i<4;i++)
        {
            bool lecturaActual = (estadoPcf & (1 << i)) != 0;

            if (lecturaActual != ultimaLecturaBoton[i])
            {
                ultimaLecturaBoton[i] = lecturaActual;
                ultimoCambioBoton[i] = millis();
            }

            if ((millis() - ultimoCambioBoton[i]) >= DEBOUNCE_MS &&
                estadoEstableBoton[i] != ultimaLecturaBoton[i])
            {
                estadoEstableBoton[i] = ultimaLecturaBoton[i];

                if (estadoEstableBoton[i] == LOW)
                {
                    if(i==0) agregarLlamado(301);
                    if(i==1) agregarLlamado(302);
                    if(i==2) agregarLlamado(303);
                    if(i==3) agregarLlamado(304);
                }
            }
        }
    }

    ui_tick();
    lv_timer_handler();
    actualizarTiempos();
    actualizarTiemposHabitaciones();
    delay(5);
}
