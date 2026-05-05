#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_PANTALLA_1 = 1,
    SCREEN_ID_PANTALLA_2 = 2,
    SCREEN_ID_PANTALLA_3 = 3,
    SCREEN_ID_PANTALLA_4 = 4,
    SCREEN_ID_PANTALLA_5 = 5,
    SCREEN_ID_PANTALLA_6 = 6,
    _SCREEN_ID_LAST = 6
};

typedef struct _objects_t {
    lv_obj_t *pantalla_1;
    lv_obj_t *pantalla_2;
    lv_obj_t *pantalla_3;
    lv_obj_t *pantalla_4;
    lv_obj_t *pantalla_5;
    lv_obj_t *pantalla_6;
    lv_obj_t *obj0;
    lv_obj_t *btn_ingresar;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *lbl_estado;
    lv_obj_t *btn_atender;
    lv_obj_t *btn_301;
    lv_obj_t *btn_302;
    lv_obj_t *btn_303;
    lv_obj_t *btn_304;
    lv_obj_t *tarjeta1;
    lv_obj_t *lbl_tarjeta1;
    lv_obj_t *lbl_time1;
    lv_obj_t *tarjeta2;
    lv_obj_t *lbl_tarjeta2;
    lv_obj_t *lbl_time2;
    lv_obj_t *tarjeta3;
    lv_obj_t *lbl_tarjeta3;
    lv_obj_t *lbl_time3;
    lv_obj_t *tarjeta4;
    lv_obj_t *lbl_tarjeta4;
    lv_obj_t *lbl_time4;
    lv_obj_t *btn_salir;
    lv_obj_t *led_amarillo;
    lv_obj_t *led_rojo;
    lv_obj_t *led_verde;
    lv_obj_t *btn_regresar1;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *lbl_info_301;
    lv_obj_t *lbl_estado_301;
    lv_obj_t *lbl_llamado_301;
    lv_obj_t *lbl_tiempo_301;
    lv_obj_t *obj5;
    lv_obj_t *lbl_info_302;
    lv_obj_t *lbl_estado_302;
    lv_obj_t *lbl_llamado_302;
    lv_obj_t *lbl_tiempo_302;
    lv_obj_t *btn_regresar2;
    lv_obj_t *obj6;
    lv_obj_t *lbl_info_303;
    lv_obj_t *lbl_estado_303;
    lv_obj_t *lbl_llamado_303;
    lv_obj_t *lbl_tiempo_303;
    lv_obj_t *btn_regresar3;
    lv_obj_t *obj7;
    lv_obj_t *lbl_info_304;
    lv_obj_t *lbl_estado_304;
    lv_obj_t *lbl_llamado_304;
    lv_obj_t *lbl_tiempo_304;
    lv_obj_t *btn_regresar4;
} objects_t;

extern objects_t objects;

void create_screen_pantalla_1();
void tick_screen_pantalla_1();

void create_screen_pantalla_2();
void tick_screen_pantalla_2();

void create_screen_pantalla_3();
void tick_screen_pantalla_3();

void create_screen_pantalla_4();
void tick_screen_pantalla_4();

void create_screen_pantalla_5();
void tick_screen_pantalla_5();

void create_screen_pantalla_6();
void tick_screen_pantalla_6();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/