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


void setup_scr_screen_setting(lv_ui *ui)
{
	//Write codes screen_setting
	ui->screen_setting = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_setting, 320, 240);

	//Write style for screen_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_cont_top
	ui->screen_setting_cont_top = lv_obj_create(ui->screen_setting);
	lv_obj_set_pos(ui->screen_setting_cont_top, 5, 5);
	lv_obj_set_size(ui->screen_setting_cont_top, 310, 180);
	lv_obj_set_scrollbar_mode(ui->screen_setting_cont_top, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_setting_cont_top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_cont_top, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_cont_top, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_cont_top, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_cont_top, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_cont_top, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_ddlist_ssid
	ui->screen_setting_ddlist_ssid = lv_dropdown_create(ui->screen_setting_cont_top);
	lv_dropdown_set_options(ui->screen_setting_ddlist_ssid, "");
	lv_obj_set_pos(ui->screen_setting_ddlist_ssid, 116, 12);
	lv_obj_set_size(ui->screen_setting_ddlist_ssid, 160, 30);

	//Write style for screen_setting_ddlist_ssid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_setting_ddlist_ssid, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_ddlist_ssid, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_ddlist_ssid, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_ddlist_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_ddlist_ssid, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_ddlist_ssid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_ddlist_ssid, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_ddlist_ssid, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_ddlist_ssid, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_ddlist_ssid, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_ddlist_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_ddlist_ssid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_ddlist_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_setting_ddlist_ssid_extra_list_selected_checked
	static lv_style_t style_screen_setting_ddlist_ssid_extra_list_selected_checked;
	ui_init_style(&style_screen_setting_ddlist_ssid_extra_list_selected_checked);
	
	lv_style_set_text_color(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_style_set_border_width(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_setting_ddlist_ssid_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_setting_ddlist_ssid), &style_screen_setting_ddlist_ssid_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_setting_ddlist_ssid_extra_list_main_default
	static lv_style_t style_screen_setting_ddlist_ssid_extra_list_main_default;
	ui_init_style(&style_screen_setting_ddlist_ssid_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_setting_ddlist_ssid_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_setting_ddlist_ssid_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_setting_ddlist_ssid_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_border_width(&style_screen_setting_ddlist_ssid_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_setting_ddlist_ssid_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_setting_ddlist_ssid_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_setting_ddlist_ssid_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_setting_ddlist_ssid_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_setting_ddlist_ssid_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_setting_ddlist_ssid_extra_list_main_default, lv_color_hex(0xffffff));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_setting_ddlist_ssid), &style_screen_setting_ddlist_ssid_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_setting_ddlist_ssid_extra_list_scrollbar_default
	static lv_style_t style_screen_setting_ddlist_ssid_extra_list_scrollbar_default;
	ui_init_style(&style_screen_setting_ddlist_ssid_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_setting_ddlist_ssid_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_setting_ddlist_ssid_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_setting_ddlist_ssid_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_setting_ddlist_ssid), &style_screen_setting_ddlist_ssid_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_2
	ui->screen_setting_label_2 = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_2, "WIFI名称:");
	lv_label_set_long_mode(ui->screen_setting_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_2, 24, 19);
	lv_obj_set_size(ui->screen_setting_label_2, 80, 22);

	//Write style for screen_setting_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_2, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_2, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_3
	ui->screen_setting_label_3 = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_3, "WIFI密码:");
	lv_label_set_long_mode(ui->screen_setting_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_3, 24, 58);
	lv_obj_set_size(ui->screen_setting_label_3, 80, 22);

	//Write style for screen_setting_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_3, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_3, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_ta_passwd
	ui->screen_setting_ta_passwd = lv_textarea_create(ui->screen_setting_cont_top);
	lv_textarea_set_text(ui->screen_setting_ta_passwd, "");
	lv_textarea_set_password_bullet(ui->screen_setting_ta_passwd, "*");
	lv_textarea_set_password_mode(ui->screen_setting_ta_passwd, true);
	lv_textarea_set_one_line(ui->screen_setting_ta_passwd, true);
	lv_obj_set_pos(ui->screen_setting_ta_passwd, 116, 51);
	lv_obj_set_size(ui->screen_setting_ta_passwd, 160, 30);

	//Write style for screen_setting_ta_passwd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_setting_ta_passwd, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_ta_passwd, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_ta_passwd, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_ta_passwd, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_ta_passwd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_ta_passwd, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_ta_passwd, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_ta_passwd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_ta_passwd, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_ta_passwd, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_ta_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_ta_passwd, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_ta_passwd, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_ta_passwd, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_ta_passwd, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_setting_ta_passwd, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_ta_passwd, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_ta_passwd, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_ta_passwd, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_state
	ui->screen_setting_label_state = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_state, "连接中...");
	lv_label_set_long_mode(ui->screen_setting_label_state, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_state, 116, 148);
	lv_obj_set_size(ui->screen_setting_label_state, 80, 22);
	lv_obj_add_flag(ui->screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_setting_label_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_state, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_state, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_state, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_state, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_5
	ui->screen_setting_label_5 = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_5, "IP地址:");
	lv_label_set_long_mode(ui->screen_setting_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_5, 43, 100);
	lv_obj_set_size(ui->screen_setting_label_5, 60, 22);

	//Write style for screen_setting_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_5, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_5, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_ip_addr
	ui->screen_setting_label_ip_addr = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_ip_addr, "0.0.0.0");
	lv_label_set_long_mode(ui->screen_setting_label_ip_addr, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_ip_addr, 116, 99);
	lv_obj_set_size(ui->screen_setting_label_ip_addr, 160, 22);

	//Write style for screen_setting_label_ip_addr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_ip_addr, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_label_ip_addr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_label_ip_addr, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_label_ip_addr, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_ip_addr, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_ip_addr, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_ip_addr, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_ip_addr, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_ip_addr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_btn_connect
	ui->screen_setting_btn_connect = lv_btn_create(ui->screen_setting_cont_top);
	ui->screen_setting_btn_connect_label = lv_label_create(ui->screen_setting_btn_connect);
	lv_label_set_text(ui->screen_setting_btn_connect_label, "连接");
	lv_label_set_long_mode(ui->screen_setting_btn_connect_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_setting_btn_connect_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_setting_btn_connect, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_setting_btn_connect, 236, 140);
	lv_obj_set_size(ui->screen_setting_btn_connect, 64, 32);

	//Write style for screen_setting_btn_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_btn_connect, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_btn_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_btn_connect, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_btn_connect, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_btn_connect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_btn_connect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_btn_connect, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_btn_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_btn_search
	ui->screen_setting_btn_search = lv_btn_create(ui->screen_setting_cont_top);
	ui->screen_setting_btn_search_label = lv_label_create(ui->screen_setting_btn_search);
	lv_label_set_text(ui->screen_setting_btn_search_label, "搜索");
	lv_label_set_long_mode(ui->screen_setting_btn_search_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_setting_btn_search_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_setting_btn_search, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_setting_btn_search, 8, 140);
	lv_obj_set_size(ui->screen_setting_btn_search, 64, 32);

	//Write style for screen_setting_btn_search, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_btn_search, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_btn_search, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_btn_search, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_btn_search, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_btn_search, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_btn_search, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_btn_search, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_btn_search, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_btn_search, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_btn_search, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_btn_search, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_txt_14
	ui->screen_setting_label_txt_14 = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_txt_14, "搜索中连接已...");
	lv_label_set_long_mode(ui->screen_setting_label_txt_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_txt_14, 17, 121);
	lv_obj_set_size(ui->screen_setting_label_txt_14, 10, 10);
	lv_obj_add_flag(ui->screen_setting_label_txt_14, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_setting_label_txt_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_txt_14, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_txt_14, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_txt_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_txt_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_txt_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_txt_16
	ui->screen_setting_label_txt_16 = lv_label_create(ui->screen_setting_cont_top);
	lv_label_set_text(ui->screen_setting_label_txt_16, "连接断开");
	lv_label_set_long_mode(ui->screen_setting_label_txt_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_txt_16, 40, 120);
	lv_obj_set_size(ui->screen_setting_label_txt_16, 10, 10);
	lv_obj_add_flag(ui->screen_setting_label_txt_16, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_setting_label_txt_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_txt_16, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_txt_16, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_txt_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_txt_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_txt_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_cont_bottom
	ui->screen_setting_cont_bottom = lv_obj_create(ui->screen_setting);
	lv_obj_set_pos(ui->screen_setting_cont_bottom, 5, 191);
	lv_obj_set_size(ui->screen_setting_cont_bottom, 310, 46);
	lv_obj_set_scrollbar_mode(ui->screen_setting_cont_bottom, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_setting_cont_bottom, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_cont_bottom, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_cont_bottom, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_cont_bottom, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_cont_bottom, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_cont_bottom, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_cont_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_label_1
	ui->screen_setting_label_1 = lv_label_create(ui->screen_setting_cont_bottom);
	lv_label_set_text(ui->screen_setting_label_1, "亮度:");
	lv_label_set_long_mode(ui->screen_setting_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_setting_label_1, 2, 12);
	lv_obj_set_size(ui->screen_setting_label_1, 50, 22);

	//Write style for screen_setting_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_label_1, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_setting_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_slider_led
	ui->screen_setting_slider_led = lv_slider_create(ui->screen_setting_cont_bottom);
	lv_slider_set_range(ui->screen_setting_slider_led, 1, 10);
	lv_slider_set_mode(ui->screen_setting_slider_led, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_setting_slider_led, 5, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_setting_slider_led, 62, 16);
	lv_obj_set_size(ui->screen_setting_slider_led, 100, 8);

	//Write style for screen_setting_slider_led, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_slider_led, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_slider_led, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_slider_led, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_setting_slider_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_slider_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_setting_slider_led, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_slider_led, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_slider_led, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_slider_led, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_setting_slider_led, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_slider_led, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_slider_led, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_slider_led, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_setting_btn_back
	ui->screen_setting_btn_back = lv_btn_create(ui->screen_setting_cont_bottom);
	ui->screen_setting_btn_back_label = lv_label_create(ui->screen_setting_btn_back);
	lv_label_set_text(ui->screen_setting_btn_back_label, "返回");
	lv_label_set_long_mode(ui->screen_setting_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_setting_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_setting_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_setting_btn_back, 245, 6);
	lv_obj_set_size(ui->screen_setting_btn_back, 56, 32);

	//Write style for screen_setting_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_btn_back, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_btn_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_btn_back, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_btn_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_btn_back, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_setting_btn_reset
	ui->screen_setting_btn_reset = lv_btn_create(ui->screen_setting_cont_bottom);
	ui->screen_setting_btn_reset_label = lv_label_create(ui->screen_setting_btn_reset);
	lv_label_set_text(ui->screen_setting_btn_reset_label, "重置");
	lv_label_set_long_mode(ui->screen_setting_btn_reset_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_setting_btn_reset_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_setting_btn_reset, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_setting_btn_reset, 174, 6);
	lv_obj_set_size(ui->screen_setting_btn_reset, 56, 32);

	//Write style for screen_setting_btn_reset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_setting_btn_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_setting_btn_reset, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_setting_btn_reset, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_setting_btn_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_setting_btn_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_setting_btn_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_setting_btn_reset, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_setting_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_setting_btn_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_setting_btn_reset, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_setting_btn_reset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_setting);

	
}
