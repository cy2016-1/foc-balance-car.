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


void setup_scr_screen_camera(lv_ui *ui)
{
	//Write codes screen_camera
	ui->screen_camera = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_camera, 320, 240);

	//Write style for screen_camera, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_camera, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_camera, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_img_cam
	ui->screen_camera_img_cam = lv_img_create(ui->screen_camera);
	lv_obj_add_flag(ui->screen_camera_img_cam, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->screen_camera_img_cam, 50,50);
	lv_img_set_angle(ui->screen_camera_img_cam, 0);
	lv_obj_set_pos(ui->screen_camera_img_cam, 0, 0);
	lv_obj_set_size(ui->screen_camera_img_cam, 320, 240);

	//Write style for screen_camera_img_cam, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_camera_img_cam, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_btn_back
	ui->screen_camera_btn_back = lv_btn_create(ui->screen_camera);
	ui->screen_camera_btn_back_label = lv_label_create(ui->screen_camera_btn_back);
	lv_label_set_text(ui->screen_camera_btn_back_label, "返回");
	lv_label_set_long_mode(ui->screen_camera_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_camera_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_camera_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_camera_btn_back, 252, 8);
	lv_obj_set_size(ui->screen_camera_btn_back, 60, 35);

	//Write style for screen_camera_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_camera_btn_back, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_camera_btn_back, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_camera_btn_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_camera_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_camera_btn_back, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_camera_btn_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_btn_back, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_label_4
	ui->screen_camera_label_4 = lv_label_create(ui->screen_camera);
	lv_label_set_text(ui->screen_camera_label_4, "速度:");
	lv_label_set_long_mode(ui->screen_camera_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_camera_label_4, 12, 210);
	lv_obj_set_size(ui->screen_camera_label_4, 48, 22);

	//Write style for screen_camera_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_label_4, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_camera_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_camera_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_label_velocity
	ui->screen_camera_label_velocity = lv_label_create(ui->screen_camera);
	lv_label_set_text(ui->screen_camera_label_velocity, "0.0");
	lv_label_set_long_mode(ui->screen_camera_label_velocity, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_camera_label_velocity, 60, 210);
	lv_obj_set_size(ui->screen_camera_label_velocity, 64, 22);

	//Write style for screen_camera_label_velocity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_label_velocity, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_label_velocity, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_camera_label_velocity, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_label_velocity, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_camera_label_velocity, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_label_velocity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_label_2
	ui->screen_camera_label_2 = lv_label_create(ui->screen_camera);
	lv_label_set_text(ui->screen_camera_label_2, ":转向");
	lv_label_set_long_mode(ui->screen_camera_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_camera_label_2, 260, 210);
	lv_obj_set_size(ui->screen_camera_label_2, 48, 22);

	//Write style for screen_camera_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_label_2, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_camera_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_camera_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_label_turn
	ui->screen_camera_label_turn = lv_label_create(ui->screen_camera);
	lv_label_set_text(ui->screen_camera_label_turn, "0.0");
	lv_label_set_long_mode(ui->screen_camera_label_turn, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_camera_label_turn, 196, 210);
	lv_obj_set_size(ui->screen_camera_label_turn, 64, 22);

	//Write style for screen_camera_label_turn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_label_turn, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_label_turn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_camera_label_turn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_label_turn, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_camera_label_turn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_label_turn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_camera_btn_photo
	ui->screen_camera_btn_photo = lv_btn_create(ui->screen_camera);
	ui->screen_camera_btn_photo_label = lv_label_create(ui->screen_camera_btn_photo);
	lv_label_set_text(ui->screen_camera_btn_photo_label, "拍照");
	lv_label_set_long_mode(ui->screen_camera_btn_photo_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_camera_btn_photo_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_camera_btn_photo, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_camera_btn_photo, 8, 8);
	lv_obj_set_size(ui->screen_camera_btn_photo, 60, 35);

	//Write style for screen_camera_btn_photo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_camera_btn_photo, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_camera_btn_photo, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_camera_btn_photo, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_camera_btn_photo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_camera_btn_photo, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_camera_btn_photo, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_camera_btn_photo, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_camera_btn_photo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_camera_btn_photo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_camera_btn_photo, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_camera_btn_photo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_camera);

	
}
