#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

static const char *screen_names[] = { "pantalla_1", "pantalla_2", "pantalla_3", "pantalla_4", "pantalla_5", "pantalla_6" };
static const char *object_names[] = { "pantalla_1", "pantalla_2", "pantalla_3", "pantalla_4", "pantalla_5", "pantalla_6", "obj0", "btn_ingresar", "obj1", "obj2", "lbl_estado", "btn_atender", "btn_301", "btn_302", "btn_303", "btn_304", "tarjeta1", "lbl_tarjeta1", "lbl_time1", "tarjeta2", "lbl_tarjeta2", "lbl_time2", "tarjeta3", "lbl_tarjeta3", "lbl_time3", "tarjeta4", "lbl_tarjeta4", "lbl_time4", "btn_salir", "btn_call_301", "btn_call_302", "btn_call_303", "btn_call_304", "led_amarillo", "led_rojo", "led_verde", "btn_regresar1", "obj3", "obj4", "lbl_info_301", "lbl_estado_301", "lbl_llamado_301", "lbl_tiempo_301", "obj5", "lbl_info_302", "lbl_estado_302", "lbl_llamado_302", "lbl_tiempo_302", "btn_regresar2", "obj6", "lbl_info_303", "lbl_estado_303", "lbl_llamado_303", "lbl_tiempo_303", "btn_regresar3", "obj7", "lbl_info_304", "lbl_estado_304", "lbl_llamado_304", "lbl_tiempo_304", "btn_regresar4" };

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_pantalla_1_btn_ingresar(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_pantalla_2_btn_301(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_pantalla_2_btn_302(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_pantalla_2_btn_303(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_pantalla_2_btn_304(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_pantalla_2_btn_salir(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 29, 0, e);
    }
}

static void event_handler_cb_pantalla_3_btn_regresar1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_pantalla_4_btn_regresar2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_pantalla_5_btn_regresar3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_pantalla_6_btn_regresar4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

//
// Screens
//

void create_screen_pantalla_1() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd9edf9), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 131, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff3b3636), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "   CENTRAL DE LLAMADOS\nAREA DE HOSPITALIZACION");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_biomedica_logo);
            lv_img_set_zoom(obj, 260);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ecci_logo);
            lv_img_set_zoom(obj, 250);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 174, 399);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_label_set_text(obj, "ELABORADO POR:\n\n");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 70, 431);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Juan Jose Cortes\n");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 73, 455);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Carlos Ivan Arias\n");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 295, 431);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Jheremy Parra\n");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 281, 455);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Valentina Cordoba");
        }
        {
            // btn_ingresar
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ingresar = obj;
            lv_obj_set_pos(obj, 161, 231);
            lv_obj_set_size(obj, 160, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_1_btn_ingresar, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "INGRESAR");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 152, 194);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff504e4e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "INICIAR SISTEMA:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 135, 367);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SISTEMAS DIGITALES II");
        }
    }
    
    tick_screen_pantalla_1();
}

void tick_screen_pantalla_1() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_pantalla_2() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd9edf9), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 99, 20);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "CENTRAL DE LLAMADOS");
        }
        {
            // lbl_estado
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_estado = obj;
            lv_obj_set_pos(obj, 180, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SISTEMA ACTIVO");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 30, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "LLAMADOS:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 25, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "--------------------------------------------------------------------------------------");
        }
        {
            // btn_atender
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_atender = obj;
            lv_obj_set_pos(obj, 155, 310);
            lv_obj_set_size(obj, 170, 53);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2e7d32), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ATENDER LLAMADO");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 30, 372);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "--------------------------------------------------------------------------------------");
        }
        {
            // btn_301
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_301 = obj;
            lv_obj_set_pos(obj, 25, 412);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_2_btn_301, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "301");
                }
            }
        }
        {
            // btn_302
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_302 = obj;
            lv_obj_set_pos(obj, 140, 412);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_2_btn_302, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "302");
                }
            }
        }
        {
            // btn_303
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_303 = obj;
            lv_obj_set_pos(obj, 250, 412);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_2_btn_303, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "303");
                }
            }
        }
        {
            // btn_304
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_304 = obj;
            lv_obj_set_pos(obj, 360, 412);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_2_btn_304, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "304");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 186, 388);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "HABITACIONES");
        }
        {
            // tarjeta1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.tarjeta1 = obj;
            lv_obj_set_pos(obj, 21, 110);
            lv_obj_set_size(obj, 440, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffcdd2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_tarjeta1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tarjeta1 = obj;
                    lv_obj_set_pos(obj, 176, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "----------");
                }
                {
                    // lbl_time1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_time1 = obj;
                    lv_obj_set_pos(obj, 294, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:00");
                }
            }
        }
        {
            // tarjeta2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.tarjeta2 = obj;
            lv_obj_set_pos(obj, 20, 157);
            lv_obj_set_size(obj, 440, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffff9c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_tarjeta2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tarjeta2 = obj;
                    lv_obj_set_pos(obj, 177, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "----------");
                }
                {
                    // lbl_time2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_time2 = obj;
                    lv_obj_set_pos(obj, 295, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:00");
                }
            }
        }
        {
            // tarjeta3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.tarjeta3 = obj;
            lv_obj_set_pos(obj, 20, 210);
            lv_obj_set_size(obj, 440, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffa4d7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_tarjeta3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tarjeta3 = obj;
                    lv_obj_set_pos(obj, 177, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "----------");
                }
                {
                    // lbl_time3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_time3 = obj;
                    lv_obj_set_pos(obj, 295, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:00");
                }
            }
        }
        {
            // tarjeta4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.tarjeta4 = obj;
            lv_obj_set_pos(obj, 20, 260);
            lv_obj_set_size(obj, 440, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffa4d7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_tarjeta4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tarjeta4 = obj;
                    lv_obj_set_pos(obj, 177, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "----------");
                }
                {
                    // lbl_time4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_time4 = obj;
                    lv_obj_set_pos(obj, 295, -11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:00");
                }
            }
        }
        {
            // btn_salir
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_salir = obj;
            lv_obj_set_pos(obj, 19, 16);
            lv_obj_set_size(obj, 50, 28);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_2_btn_salir, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff13c3c), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "salir");
                }
            }
        }
        {
            // btn_call_301
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_call_301 = obj;
            lv_obj_set_pos(obj, 30, 297);
            lv_obj_set_size(obj, 85, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3af21), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "301 CALL");
                }
            }
        }
        {
            // btn_call_302
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_call_302 = obj;
            lv_obj_set_pos(obj, 30, 336);
            lv_obj_set_size(obj, 85, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3af21), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "302 CALL");
                }
            }
        }
        {
            // btn_call_303
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_call_303 = obj;
            lv_obj_set_pos(obj, 360, 297);
            lv_obj_set_size(obj, 85, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3af21), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "303 CALL");
                }
            }
        }
        {
            // btn_call_304
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_call_304 = obj;
            lv_obj_set_pos(obj, 360, 336);
            lv_obj_set_size(obj, 85, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3af21), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "304 CALL");
                }
            }
        }
        {
            // led_amarillo
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.led_amarillo = obj;
            lv_obj_set_pos(obj, 393, 53);
            lv_obj_set_size(obj, 19, 17);
            lv_led_set_color(obj, lv_color_hex(0xfffffb0f));
            lv_led_set_brightness(obj, 255);
        }
        {
            // led_rojo
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.led_rojo = obj;
            lv_obj_set_pos(obj, 426, 53);
            lv_obj_set_size(obj, 19, 17);
            lv_led_set_color(obj, lv_color_hex(0xffff0000));
            lv_led_set_brightness(obj, 255);
        }
        {
            // led_verde
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.led_verde = obj;
            lv_obj_set_pos(obj, 362, 53);
            lv_obj_set_size(obj, 19, 17);
            lv_led_set_color(obj, lv_color_hex(0xff00f102));
            lv_led_set_brightness(obj, 255);
        }
    }
    
    tick_screen_pantalla_2();
}

void tick_screen_pantalla_2() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_pantalla_3() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcde7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btn_regresar1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_regresar1 = obj;
            lv_obj_set_pos(obj, 190, 340);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_3_btn_regresar1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "REGRESAR");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 147, 32);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HABITACION 301");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 90, 68);
            lv_obj_set_size(obj, 300, 244);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeaf4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_info_301
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_info_301 = obj;
                    lv_obj_set_pos(obj, 5, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "NOMBRE: CAMILA ANDREA FARFAN\n\nEDAD: 19 ANOS\n\nEPS: COLSANITAS\n\n");
                }
                {
                    // lbl_estado_301
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_estado_301 = obj;
                    lv_obj_set_pos(obj, 5, 126);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ESTADO: OBSERVACION");
                }
                {
                    // lbl_llamado_301
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_llamado_301 = obj;
                    lv_obj_set_pos(obj, 5, 158);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LLAMADO: SIN LLAMADO");
                }
                {
                    // lbl_tiempo_301
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tiempo_301 = obj;
                    lv_obj_set_pos(obj, 5, 187);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "TIEMPO: 00:00");
                }
            }
        }
    }
    
    tick_screen_pantalla_3();
}

void tick_screen_pantalla_3() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_pantalla_4() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcde7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 155, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HABITACION 302");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 90, 73);
            lv_obj_set_size(obj, 300, 252);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeaf4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_info_302
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_info_302 = obj;
                    lv_obj_set_pos(obj, 4, 6);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NOMBRE: ANA MARIA ZAMBRANO\n\nEDAD: 21 ANOS\n\nEPS: FAMISANAR");
                }
                {
                    // lbl_estado_302
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_estado_302 = obj;
                    lv_obj_set_pos(obj, 0, 121);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ESTADO: RECUPERACION");
                }
                {
                    // lbl_llamado_302
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_llamado_302 = obj;
                    lv_obj_set_pos(obj, 1, 149);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LLAMADO: SIN LLAMADO");
                }
                {
                    // lbl_tiempo_302
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tiempo_302 = obj;
                    lv_obj_set_pos(obj, 1, 178);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "TIEMPO: 00:00");
                }
            }
        }
        {
            // btn_regresar2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_regresar2 = obj;
            lv_obj_set_pos(obj, 185, 361);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_4_btn_regresar2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "REGRESAR");
                }
            }
        }
    }
    
    tick_screen_pantalla_4();
}

void tick_screen_pantalla_4() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
}

void create_screen_pantalla_5() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcde7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 155, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HABITACION 303");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 82, 71);
            lv_obj_set_size(obj, 306, 231);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeaf4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_info_303
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_info_303 = obj;
                    lv_obj_set_pos(obj, -5, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NOMBRE: CARLOS DAVID RODRIGUEZ\n\nEDAD: 45 ANOS\n\nEPS: COMPENSAR");
                }
                {
                    // lbl_estado_303
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_estado_303 = obj;
                    lv_obj_set_pos(obj, -9, 119);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ESTADO: RECUPERACION");
                }
                {
                    // lbl_llamado_303
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_llamado_303 = obj;
                    lv_obj_set_pos(obj, -9, 143);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LLAMADO: SIN LLAMADO");
                }
                {
                    // lbl_tiempo_303
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tiempo_303 = obj;
                    lv_obj_set_pos(obj, -9, 170);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "TIEMPO: 00:00");
                }
            }
        }
        {
            // btn_regresar3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_regresar3 = obj;
            lv_obj_set_pos(obj, 185, 361);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_5_btn_regresar3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "REGRESAR");
                }
            }
        }
    }
    
    tick_screen_pantalla_5();
}

void tick_screen_pantalla_5() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
}

void create_screen_pantalla_6() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pantalla_6 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcde7fc), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 155, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HABITACION 304");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 90, 73);
            lv_obj_set_size(obj, 300, 218);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeaf4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_info_304
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_info_304 = obj;
                    lv_obj_set_pos(obj, 4, 6);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NOMBRE: JUAN DIEGO OTIS\n\nEDAD: 56 ANOS\n\nEPS: SANITAS");
                }
                {
                    // lbl_estado_304
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_estado_304 = obj;
                    lv_obj_set_pos(obj, 1, 108);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ESTADO: RECUPERACION");
                }
                {
                    // lbl_llamado_304
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_llamado_304 = obj;
                    lv_obj_set_pos(obj, 1, 133);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LLAMADO: SIN LLAMADO");
                }
                {
                    // lbl_tiempo_304
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_tiempo_304 = obj;
                    lv_obj_set_pos(obj, 1, 159);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "TIEMPO: 00:00");
                }
            }
        }
        {
            // btn_regresar4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_regresar4 = obj;
            lv_obj_set_pos(obj, 185, 361);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_pantalla_6_btn_regresar4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1976d2), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "REGRESAR");
                }
            }
        }
    }
    
    tick_screen_pantalla_6();
}

void tick_screen_pantalla_6() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_pantalla_1,
    tick_screen_pantalla_2,
    tick_screen_pantalla_3,
    tick_screen_pantalla_4,
    tick_screen_pantalla_5,
    tick_screen_pantalla_6,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
//
//

void create_screens() {
    
    eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    // Create screens
    create_screen_pantalla_1();
    create_screen_pantalla_2();
    create_screen_pantalla_3();
    create_screen_pantalla_4();
    create_screen_pantalla_5();
    create_screen_pantalla_6();
}