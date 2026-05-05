#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <lvgl.h>
#include "Arduino_GFX_Library.h"

#include "ui.h"
#include "screens.h"
#include "eez-flow.h"

#define USBSerial Serial

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480

#define TOUCH_SDA 15
#define TOUCH_SCL 7

#define GT911_ADDR_1 0x5D
#define GT911_ADDR_2 0x14

// CONFIGURACIÓN CORREGIDA
#define TOUCH_SWAP_XY 0
#define TOUCH_INVERT_X 1
#define TOUCH_INVERT_Y 1
#define TOUCH_DEBUG 0
uint8_t gt911Addr = GT911_ADDR_1;
bool touchOK = false;
uint16_t touchX = 0;
uint16_t touchY = 0;

//--------------------------------------------------
// DISPLAY
//--------------------------------------------------

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

//--------------------------------------------------
// LVGL
//--------------------------------------------------

static lv_disp_draw_buf_t draw_buf;
static lv_color_t draw_buf_1[SCREEN_WIDTH * 10];

//--------------------------------------------------

bool i2cDevicePresent(uint8_t addr)
{
    Wire.beginTransmission(addr);
    return Wire.endTransmission() == 0;
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
    if (i2cDevicePresent(GT911_ADDR_1)) {
        gt911Addr = GT911_ADDR_1;
        gt911WriteByte(0x814E, 0);
        return true;
    }

    if (i2cDevicePresent(GT911_ADDR_2)) {
        gt911Addr = GT911_ADDR_2;
        gt911WriteByte(0x814E, 0);
        return true;
    }

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

//--------------------------------------------------

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

//--------------------------------------------------

void my_touch_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    static int lastX = 0;
    static int lastY = 0;

    if (readTouch()) {

        int x = touchX;
        int y = touchY;

#if TOUCH_SWAP_XY
        int t = x;
        x = y;
        y = t;
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
    else {
        data->state = LV_INDEV_STATE_REL;
        data->point.x = lastX;
        data->point.y = lastY;
    }
}

//--------------------------------------------------

void setup()
{
    USBSerial.begin(115200);

    Wire.begin(TOUCH_SDA, TOUCH_SCL);
    Wire.setClock(100000);

    // power panel
    Wire.beginTransmission(0x24);
    Wire.write(0x02);
    Wire.write(0xFF);
    Wire.endTransmission();

    Wire.beginTransmission(0x24);
    Wire.write(0x03);
    Wire.write(0x3A);
    Wire.endTransmission();

    touchOK = initTouch();

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

    USBSerial.println("Sistema hospitalario iniciado");
}

//--------------------------------------------------

void loop()
{
    static uint32_t lastTick = millis();
    uint32_t now = millis();

    lv_tick_inc(now - lastTick);
    lastTick = now;

    ui_tick();
    lv_timer_handler();

    delay(5);
}