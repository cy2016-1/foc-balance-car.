/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_main;
	bool screen_main_del;
	lv_obj_t *screen_main_imgbtn_camera;
	lv_obj_t *screen_main_imgbtn_camera_label;
	lv_obj_t *screen_main_imgbtn_pid;
	lv_obj_t *screen_main_imgbtn_pid_label;
	lv_obj_t *screen_main_imgbtn_setting;
	lv_obj_t *screen_main_imgbtn_setting_label;
	lv_obj_t *screen_main_imgbtn_about;
	lv_obj_t *screen_main_imgbtn_about_label;
	lv_obj_t *screen_main_img_wifi;
	lv_obj_t *screen_data;
	bool screen_data_del;
	lv_obj_t *screen_data_btn_query;
	lv_obj_t *screen_data_btn_query_label;
	lv_obj_t *screen_data_btn_back;
	lv_obj_t *screen_data_btn_back_label;
	lv_obj_t *screen_data_tabview_data;
	lv_obj_t *screen_data_tabview_data_tab_1;
	lv_obj_t *screen_data_tabview_data_tab_2;
	lv_obj_t *screen_data_tabview_data_tab_3;
	lv_obj_t *screen_data_tabview_data_tab_4;
	lv_obj_t *screen_data_tabview_data_tab_5;
	lv_obj_t *screen_data_label_1;
	lv_obj_t *screen_data_label_2;
	lv_obj_t *screen_data_label_3;
	lv_obj_t *screen_data_spinbox_vel_p;
	lv_obj_t *screen_data_spinbox_vel_p_btn;
	lv_obj_t *screen_data_spinbox_vel_p_btn_minus;
	lv_obj_t *screen_data_spinbox_vel_i;
	lv_obj_t *screen_data_spinbox_vel_i_btn;
	lv_obj_t *screen_data_spinbox_vel_i_btn_minus;
	lv_obj_t *screen_data_spinbox_vel_d;
	lv_obj_t *screen_data_spinbox_vel_d_btn;
	lv_obj_t *screen_data_spinbox_vel_d_btn_minus;
	lv_obj_t *screen_data_img_1;
	lv_obj_t *screen_data_label_4;
	lv_obj_t *screen_data_label_5;
	lv_obj_t *screen_data_label_6;
	lv_obj_t *screen_data_spinbox_stand_p;
	lv_obj_t *screen_data_spinbox_stand_p_btn;
	lv_obj_t *screen_data_spinbox_stand_p_btn_minus;
	lv_obj_t *screen_data_spinbox_stand_i;
	lv_obj_t *screen_data_spinbox_stand_i_btn;
	lv_obj_t *screen_data_spinbox_stand_i_btn_minus;
	lv_obj_t *screen_data_spinbox_stand_d;
	lv_obj_t *screen_data_spinbox_stand_d_btn;
	lv_obj_t *screen_data_spinbox_stand_d_btn_minus;
	lv_obj_t *screen_data_img_2;
	lv_obj_t *screen_data_label_7;
	lv_obj_t *screen_data_label_8;
	lv_obj_t *screen_data_label_9;
	lv_obj_t *screen_data_spinbox_turn_p;
	lv_obj_t *screen_data_spinbox_turn_p_btn;
	lv_obj_t *screen_data_spinbox_turn_p_btn_minus;
	lv_obj_t *screen_data_spinbox_turn_i;
	lv_obj_t *screen_data_spinbox_turn_i_btn;
	lv_obj_t *screen_data_spinbox_turn_i_btn_minus;
	lv_obj_t *screen_data_spinbox_turn_d;
	lv_obj_t *screen_data_spinbox_turn_d_btn;
	lv_obj_t *screen_data_spinbox_turn_d_btn_minus;
	lv_obj_t *screen_data_img_3;
	lv_obj_t *screen_data_label_roll;
	lv_obj_t *screen_data_label_pitch;
	lv_obj_t *screen_data_label_yaw;
	lv_obj_t *screen_data_label_gyrox;
	lv_obj_t *screen_data_label_gyroy;
	lv_obj_t *screen_data_label_gyroz;
	lv_obj_t *screen_data_img_4;
	lv_obj_t *screen_data_label_x;
	lv_obj_t *screen_data_label_y;
	lv_obj_t *screen_data_label_sw;
	lv_obj_t *screen_data_img_5;
	lv_obj_t *screen_data_btn_reset;
	lv_obj_t *screen_data_btn_reset_label;
	lv_obj_t *screen_about;
	bool screen_about_del;
	lv_obj_t *screen_about_btn_back;
	lv_obj_t *screen_about_btn_back_label;
	lv_obj_t *screen_about_label_1;
	lv_obj_t *screen_about_label_2;
	lv_obj_t *screen_about_label_version;
	lv_obj_t *screen_about_label_date;
	lv_obj_t *screen_camera;
	bool screen_camera_del;
	lv_obj_t *screen_camera_img_cam;
	lv_obj_t *screen_camera_btn_back;
	lv_obj_t *screen_camera_btn_back_label;
	lv_obj_t *screen_camera_label_4;
	lv_obj_t *screen_camera_label_velocity;
	lv_obj_t *screen_camera_label_2;
	lv_obj_t *screen_camera_label_turn;
	lv_obj_t *screen_camera_btn_photo;
	lv_obj_t *screen_camera_btn_photo_label;
	lv_obj_t *screen_setting;
	bool screen_setting_del;
	lv_obj_t *screen_setting_cont_top;
	lv_obj_t *screen_setting_ddlist_ssid;
	lv_obj_t *screen_setting_label_2;
	lv_obj_t *screen_setting_label_3;
	lv_obj_t *screen_setting_ta_passwd;
	lv_obj_t *screen_setting_label_state;
	lv_obj_t *screen_setting_label_5;
	lv_obj_t *screen_setting_label_ip_addr;
	lv_obj_t *screen_setting_btn_connect;
	lv_obj_t *screen_setting_btn_connect_label;
	lv_obj_t *screen_setting_btn_search;
	lv_obj_t *screen_setting_btn_search_label;
	lv_obj_t *screen_setting_label_txt_14;
	lv_obj_t *screen_setting_label_txt_16;
	lv_obj_t *screen_setting_cont_bottom;
	lv_obj_t *screen_setting_label_1;
	lv_obj_t *screen_setting_slider_led;
	lv_obj_t *screen_setting_btn_back;
	lv_obj_t *screen_setting_btn_back_label;
	lv_obj_t *screen_setting_btn_reset;
	lv_obj_t *screen_setting_btn_reset_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screen_main(lv_ui *ui);
void setup_scr_screen_data(lv_ui *ui);
void setup_scr_screen_about(lv_ui *ui);
void setup_scr_screen_camera(lv_ui *ui);
void setup_scr_screen_setting(lv_ui *ui);
LV_IMG_DECLARE(_camera_64_0_alpha_64x64);
LV_IMG_DECLARE(_camera_64_1_alpha_64x64);
LV_IMG_DECLARE(_pid_64_0_alpha_64x64);
LV_IMG_DECLARE(_pid_64_1_alpha_64x64);
LV_IMG_DECLARE(_setting_64_0_alpha_64x64);
LV_IMG_DECLARE(_setting_64_1_alpha_64x64);
LV_IMG_DECLARE(_about_64_0_alpha_64x64);
LV_IMG_DECLARE(_about_64_1_alpha_64x64);
LV_IMG_DECLARE(_wifi_disconn_alpha_32x32);
LV_IMG_DECLARE(_velocity_16_alpha_16x16);
LV_IMG_DECLARE(_stand_16_alpha_16x16);
LV_IMG_DECLARE(_turn_16_alpha_16x16);
LV_IMG_DECLARE(_gyroscope_16_alpha_16x16);
LV_IMG_DECLARE(_rocker_16_alpha_16x16);
LV_IMG_DECLARE(__alpha_320x240);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_simsun_18)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_simsun_14)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_simsun_16)


#ifdef __cplusplus
}
#endif
#endif
