/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef WIDGET_INIT_H
#define WIDGET_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "gui_guider.h"

__attribute__((unused)) void kb_event_cb(lv_event_t *e);
__attribute__((unused)) void ta_event_cb(lv_event_t *e);
#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec);
#endif

extern lv_obj_t * screen_data_spinbox_vel_p;
void lv_screen_data_spinbox_vel_p_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_vel_p_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_vel_i;
void lv_screen_data_spinbox_vel_i_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_vel_i_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_vel_d;
void lv_screen_data_spinbox_vel_d_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_vel_d_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_stand_p;
void lv_screen_data_spinbox_stand_p_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_stand_p_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_stand_i;
void lv_screen_data_spinbox_stand_i_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_stand_i_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_stand_d;
void lv_screen_data_spinbox_stand_d_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_stand_d_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_turn_p;
void lv_screen_data_spinbox_turn_p_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_turn_p_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_turn_i;
void lv_screen_data_spinbox_turn_i_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_turn_i_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_data_spinbox_turn_d;
void lv_screen_data_spinbox_turn_d_increment_event_cb(lv_event_t * event);
void lv_screen_data_spinbox_turn_d_decrement_event_cb(lv_event_t * event);


#ifdef __cplusplus
}
#endif
#endif
