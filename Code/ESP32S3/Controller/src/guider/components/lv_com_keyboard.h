#ifndef _LV_COM_KEYBOARD_H
#define _LV_COM_KEYBOARD_H

#include "gui_inc.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void(*kb_ready_handle_t)(lv_obj_t* obj_com, const char* str);

typedef struct{
    lv_obj_t obj;
    lv_obj_t* label_info; //文字提示
    lv_obj_t* ta_input; //输入文本框
    lv_obj_t* kb; //键盘

    kb_ready_handle_t kb_ready_handler;
}lv_com_keyboard_t;

lv_obj_t* lv_com_keyboard_create(lv_obj_t* parent);
void lv_com_keyboard_display(lv_obj_t* obj, const char* title, const char* content, lv_display_t state);

//SET
void lv_com_keyboard_set_readycb(lv_obj_t* obj, kb_ready_handle_t handler);
void lv_com_keyboard_one_line(lv_obj_t* obj, lv_gui_state_t state);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif