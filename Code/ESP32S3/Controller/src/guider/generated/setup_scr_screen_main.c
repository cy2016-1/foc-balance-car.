/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_screen_main(lv_ui *ui)
{
	//Write codes screen_main
	ui->screen_main = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_main, 320, 240);

	//Write style for screen_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_imgbtn_camera
	ui->screen_main_imgbtn_camera = lv_imgbtn_create(ui->screen_main);
	lv_obj_add_flag(ui->screen_main_imgbtn_camera, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_camera, LV_IMGBTN_STATE_RELEASED, NULL, &_camera_64_0_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_camera, LV_IMGBTN_STATE_PRESSED, NULL, &_camera_64_1_alpha_64x64, NULL);
	ui->screen_main_imgbtn_camera_label = lv_label_create(ui->screen_main_imgbtn_camera);
	lv_label_set_text(ui->screen_main_imgbtn_camera_label, "");
	lv_label_set_long_mode(ui->screen_main_imgbtn_camera_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_imgbtn_camera_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_imgbtn_camera, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_main_imgbtn_camera, 58, 40);
	lv_obj_set_size(ui->screen_main_imgbtn_camera, 64, 64);

	//Write style for screen_main_imgbtn_camera, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_camera, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_camera, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_imgbtn_camera, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_camera, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_main_imgbtn_camera, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_camera, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_camera, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_camera, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_camera, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_main_imgbtn_camera, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_camera, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_camera, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_camera, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_camera, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_main_imgbtn_camera, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_camera, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_main_imgbtn_pid
	ui->screen_main_imgbtn_pid = lv_imgbtn_create(ui->screen_main);
	lv_obj_add_flag(ui->screen_main_imgbtn_pid, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_pid, LV_IMGBTN_STATE_RELEASED, NULL, &_pid_64_0_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_pid, LV_IMGBTN_STATE_PRESSED, NULL, &_pid_64_1_alpha_64x64, NULL);
	ui->screen_main_imgbtn_pid_label = lv_label_create(ui->screen_main_imgbtn_pid);
	lv_label_set_text(ui->screen_main_imgbtn_pid_label, "");
	lv_label_set_long_mode(ui->screen_main_imgbtn_pid_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_imgbtn_pid_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_imgbtn_pid, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_main_imgbtn_pid, 198, 40);
	lv_obj_set_size(ui->screen_main_imgbtn_pid, 64, 64);

	//Write style for screen_main_imgbtn_pid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_pid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_pid, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_imgbtn_pid, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_pid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_main_imgbtn_pid, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_pid, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_pid, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_pid, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_pid, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_main_imgbtn_pid, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_pid, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_pid, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_pid, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_pid, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_main_imgbtn_pid, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_pid, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_main_imgbtn_setting
	ui->screen_main_imgbtn_setting = lv_imgbtn_create(ui->screen_main);
	lv_obj_add_flag(ui->screen_main_imgbtn_setting, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_setting, LV_IMGBTN_STATE_RELEASED, NULL, &_setting_64_0_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_setting, LV_IMGBTN_STATE_PRESSED, NULL, &_setting_64_1_alpha_64x64, NULL);
	ui->screen_main_imgbtn_setting_label = lv_label_create(ui->screen_main_imgbtn_setting);
	lv_label_set_text(ui->screen_main_imgbtn_setting_label, "");
	lv_label_set_long_mode(ui->screen_main_imgbtn_setting_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_imgbtn_setting_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_imgbtn_setting, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_main_imgbtn_setting, 58, 136);
	lv_obj_set_size(ui->screen_main_imgbtn_setting, 64, 64);

	//Write style for screen_main_imgbtn_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_imgbtn_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_main_imgbtn_setting, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_setting, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_setting, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_main_imgbtn_setting, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_setting, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_setting, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_main_imgbtn_setting, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_setting, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_main_imgbtn_about
	ui->screen_main_imgbtn_about = lv_imgbtn_create(ui->screen_main);
	lv_obj_add_flag(ui->screen_main_imgbtn_about, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_about, LV_IMGBTN_STATE_RELEASED, NULL, &_about_64_0_alpha_64x64, NULL);
	lv_imgbtn_set_src(ui->screen_main_imgbtn_about, LV_IMGBTN_STATE_PRESSED, NULL, &_about_64_1_alpha_64x64, NULL);
	ui->screen_main_imgbtn_about_label = lv_label_create(ui->screen_main_imgbtn_about);
	lv_label_set_text(ui->screen_main_imgbtn_about_label, "");
	lv_label_set_long_mode(ui->screen_main_imgbtn_about_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_imgbtn_about_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_imgbtn_about, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_main_imgbtn_about, 198, 136);
	lv_obj_set_size(ui->screen_main_imgbtn_about, 64, 64);

	//Write style for screen_main_imgbtn_about, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_about, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_about, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_imgbtn_about, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_about, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_main_imgbtn_about, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_about, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_about, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_about, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_about, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_main_imgbtn_about, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_about, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_main_imgbtn_about, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_main_imgbtn_about, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_main_imgbtn_about, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_main_imgbtn_about, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_main_imgbtn_about, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_main_img_wifi
	ui->screen_main_img_wifi = lv_img_create(ui->screen_main);
	lv_obj_add_flag(ui->screen_main_img_wifi, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_main_img_wifi, &_wifi_disconn_alpha_32x32);
	lv_img_set_pivot(ui->screen_main_img_wifi, 50,50);
	lv_img_set_angle(ui->screen_main_img_wifi, 0);
	lv_obj_set_pos(ui->screen_main_img_wifi, 280, 8);
	lv_obj_set_size(ui->screen_main_img_wifi, 32, 32);

	//Write style for screen_main_img_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_main_img_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_main);

	
}
