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


void setup_scr_screen_data(lv_ui *ui)
{
	//Write codes screen_data
	ui->screen_data = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_data, 320, 240);

	//Write style for screen_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_btn_query
	ui->screen_data_btn_query = lv_btn_create(ui->screen_data);
	ui->screen_data_btn_query_label = lv_label_create(ui->screen_data_btn_query);
	lv_label_set_text(ui->screen_data_btn_query_label, "查询");
	lv_label_set_long_mode(ui->screen_data_btn_query_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_data_btn_query_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_data_btn_query, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_data_btn_query, 120, 188);
	lv_obj_set_size(ui->screen_data_btn_query, 80, 40);

	//Write style for screen_data_btn_query, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_btn_query, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_btn_query, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_btn_query, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_btn_query, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_btn_query, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_btn_query, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_btn_query, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_btn_query, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_btn_query, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_btn_query, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_btn_query, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_btn_back
	ui->screen_data_btn_back = lv_btn_create(ui->screen_data);
	ui->screen_data_btn_back_label = lv_label_create(ui->screen_data_btn_back);
	lv_label_set_text(ui->screen_data_btn_back_label, "返回");
	lv_label_set_long_mode(ui->screen_data_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_data_btn_back_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_data_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_data_btn_back, 230, 188);
	lv_obj_set_size(ui->screen_data_btn_back, 80, 40);

	//Write style for screen_data_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_btn_back, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_btn_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_btn_back, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_btn_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_btn_back, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_tabview_data
	ui->screen_data_tabview_data = lv_tabview_create(ui->screen_data, LV_DIR_LEFT, 60);
	lv_obj_set_pos(ui->screen_data_tabview_data, 5, 3);
	lv_obj_set_size(ui->screen_data_tabview_data, 310, 174);
	lv_obj_set_scrollbar_mode(ui->screen_data_tabview_data, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_data_tabview_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_tabview_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_tabview_data, lv_color_hex(0xeaeff3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_tabview_data, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_tabview_data, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_tabview_data, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_tabview_data, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_tabview_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_tabview_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_tabview_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_tabview_data_extra_btnm_main_default
	static lv_style_t style_screen_data_tabview_data_extra_btnm_main_default;
	ui_init_style(&style_screen_data_tabview_data_extra_btnm_main_default);
	
	lv_style_set_bg_opa(&style_screen_data_tabview_data_extra_btnm_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_tabview_data_extra_btnm_main_default, lv_color_hex(0xffffff));
	lv_style_set_border_width(&style_screen_data_tabview_data_extra_btnm_main_default, 0);
	lv_style_set_radius(&style_screen_data_tabview_data_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_data_tabview_data), &style_screen_data_tabview_data_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_tabview_data_extra_btnm_items_default
	static lv_style_t style_screen_data_tabview_data_extra_btnm_items_default;
	ui_init_style(&style_screen_data_tabview_data_extra_btnm_items_default);
	
	lv_style_set_text_color(&style_screen_data_tabview_data_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
	lv_style_set_text_font(&style_screen_data_tabview_data_extra_btnm_items_default, &lv_font_simsun_14);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_data_tabview_data), &style_screen_data_tabview_data_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_data_tabview_data_extra_btnm_items_checked
	static lv_style_t style_screen_data_tabview_data_extra_btnm_items_checked;
	ui_init_style(&style_screen_data_tabview_data_extra_btnm_items_checked);
	
	lv_style_set_text_color(&style_screen_data_tabview_data_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_style_set_text_font(&style_screen_data_tabview_data_extra_btnm_items_checked, &lv_font_simsun_14);
	lv_style_set_border_width(&style_screen_data_tabview_data_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_screen_data_tabview_data_extra_btnm_items_checked, 255);
	lv_style_set_border_color(&style_screen_data_tabview_data_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_style_set_border_side(&style_screen_data_tabview_data_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_radius(&style_screen_data_tabview_data_extra_btnm_items_checked, 0);
	lv_style_set_bg_opa(&style_screen_data_tabview_data_extra_btnm_items_checked, 60);
	lv_style_set_bg_color(&style_screen_data_tabview_data_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_data_tabview_data), &style_screen_data_tabview_data_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes 速度环
	ui->screen_data_tabview_data_tab_1 = lv_tabview_add_tab(ui->screen_data_tabview_data,"速度环");
	lv_obj_t * screen_data_tabview_data_tab_1_label = lv_label_create(ui->screen_data_tabview_data_tab_1);
	lv_label_set_text(screen_data_tabview_data_tab_1_label, "");

	//Write codes screen_data_label_1
	ui->screen_data_label_1 = lv_label_create(ui->screen_data_tabview_data_tab_1);
	lv_label_set_text(ui->screen_data_label_1, "P:");
	lv_label_set_long_mode(ui->screen_data_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_1, 2, 14);
	lv_obj_set_size(ui->screen_data_label_1, 40, 22);

	//Write style for screen_data_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_2
	ui->screen_data_label_2 = lv_label_create(ui->screen_data_tabview_data_tab_1);
	lv_label_set_text(ui->screen_data_label_2, "I :");
	lv_label_set_long_mode(ui->screen_data_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_2, 2, 68);
	lv_obj_set_size(ui->screen_data_label_2, 40, 22);

	//Write style for screen_data_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_3
	ui->screen_data_label_3 = lv_label_create(ui->screen_data_tabview_data_tab_1);
	lv_label_set_text(ui->screen_data_label_3, "D:");
	lv_label_set_long_mode(ui->screen_data_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_3, 1, 118);
	lv_obj_set_size(ui->screen_data_label_3, 40, 22);

	//Write style for screen_data_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_vel_p
	ui->screen_data_spinbox_vel_p = lv_spinbox_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_p, 93, 2);
	lv_obj_set_width(ui->screen_data_spinbox_vel_p, 76);
	lv_obj_set_height(ui->screen_data_spinbox_vel_p, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_vel_p, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_vel_p, -99999, 99999);
	lv_coord_t screen_data_spinbox_vel_p_h = lv_obj_get_height(ui->screen_data_spinbox_vel_p);
	ui->screen_data_spinbox_vel_p_btn = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_p_btn, screen_data_spinbox_vel_p_h, screen_data_spinbox_vel_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_p_btn, ui->screen_data_spinbox_vel_p, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_p_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_p_btn, lv_screen_data_spinbox_vel_p_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_vel_p_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_p_btn_minus, screen_data_spinbox_vel_p_h, screen_data_spinbox_vel_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_p_btn_minus, ui->screen_data_spinbox_vel_p, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_p_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_p_btn_minus, lv_screen_data_spinbox_vel_p_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_p, 93, 2);

	//Write style for screen_data_spinbox_vel_p, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_p, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_vel_p, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_vel_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_vel_p, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_vel_p, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_vel_p, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_vel_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_vel_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_vel_p, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_p, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_p, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_vel_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_vel_p, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_vel_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_vel_p, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_p, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_p, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_p, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_p, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_vel_p_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_vel_p_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_vel_p_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_vel_p_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_vel_p_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_vel_p_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_vel_p_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_vel_p_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_vel_p_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_vel_p_btn, &style_screen_data_spinbox_vel_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_vel_p_btn_minus, &style_screen_data_spinbox_vel_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_vel_i
	ui->screen_data_spinbox_vel_i = lv_spinbox_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_i, 93, 56);
	lv_obj_set_width(ui->screen_data_spinbox_vel_i, 76);
	lv_obj_set_height(ui->screen_data_spinbox_vel_i, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_vel_i, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_vel_i, -99999, 99999);
	lv_coord_t screen_data_spinbox_vel_i_h = lv_obj_get_height(ui->screen_data_spinbox_vel_i);
	ui->screen_data_spinbox_vel_i_btn = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_i_btn, screen_data_spinbox_vel_i_h, screen_data_spinbox_vel_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_i_btn, ui->screen_data_spinbox_vel_i, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_i_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_i_btn, lv_screen_data_spinbox_vel_i_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_vel_i_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_i_btn_minus, screen_data_spinbox_vel_i_h, screen_data_spinbox_vel_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_i_btn_minus, ui->screen_data_spinbox_vel_i, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_i_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_i_btn_minus, lv_screen_data_spinbox_vel_i_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_i, 93, 56);

	//Write style for screen_data_spinbox_vel_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_vel_i, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_vel_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_vel_i, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_vel_i, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_vel_i, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_vel_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_vel_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_vel_i, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_i, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_i, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_vel_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_vel_i, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_vel_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_vel_i, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_i, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_i, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_i, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_i, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_vel_i_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_vel_i_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_vel_i_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_vel_i_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_vel_i_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_vel_i_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_vel_i_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_vel_i_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_vel_i_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_vel_i_btn, &style_screen_data_spinbox_vel_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_vel_i_btn_minus, &style_screen_data_spinbox_vel_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_vel_d
	ui->screen_data_spinbox_vel_d = lv_spinbox_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_d, 93, 108);
	lv_obj_set_width(ui->screen_data_spinbox_vel_d, 76);
	lv_obj_set_height(ui->screen_data_spinbox_vel_d, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_vel_d, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_vel_d, -99999, 99999);
	lv_coord_t screen_data_spinbox_vel_d_h = lv_obj_get_height(ui->screen_data_spinbox_vel_d);
	ui->screen_data_spinbox_vel_d_btn = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_d_btn, screen_data_spinbox_vel_d_h, screen_data_spinbox_vel_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_d_btn, ui->screen_data_spinbox_vel_d, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_d_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_d_btn, lv_screen_data_spinbox_vel_d_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_vel_d_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_set_size(ui->screen_data_spinbox_vel_d_btn_minus, screen_data_spinbox_vel_d_h, screen_data_spinbox_vel_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_vel_d_btn_minus, ui->screen_data_spinbox_vel_d, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_vel_d_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_vel_d_btn_minus, lv_screen_data_spinbox_vel_d_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_vel_d, 93, 108);

	//Write style for screen_data_spinbox_vel_d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_d, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_vel_d, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_vel_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_vel_d, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_vel_d, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_vel_d, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_vel_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_vel_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_vel_d, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_d, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_d, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_vel_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_vel_d, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_vel_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_vel_d, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_vel_d, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_vel_d, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_vel_d, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_vel_d, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_vel_d_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_vel_d_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_vel_d_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_vel_d_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_vel_d_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_vel_d_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_vel_d_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_vel_d_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_vel_d_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_vel_d_btn, &style_screen_data_spinbox_vel_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_vel_d_btn_minus, &style_screen_data_spinbox_vel_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_img_1
	ui->screen_data_img_1 = lv_img_create(ui->screen_data_tabview_data_tab_1);
	lv_obj_add_flag(ui->screen_data_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_data_img_1, &_velocity_16_alpha_16x16);
	lv_img_set_pivot(ui->screen_data_img_1, 50,50);
	lv_img_set_angle(ui->screen_data_img_1, -20);
	lv_obj_set_pos(ui->screen_data_img_1, -8, 2);
	lv_obj_set_size(ui->screen_data_img_1, 16, 16);

	//Write style for screen_data_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_data_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes 直立环
	ui->screen_data_tabview_data_tab_2 = lv_tabview_add_tab(ui->screen_data_tabview_data,"直立环");
	lv_obj_t * screen_data_tabview_data_tab_2_label = lv_label_create(ui->screen_data_tabview_data_tab_2);
	lv_label_set_text(screen_data_tabview_data_tab_2_label, "");

	//Write codes screen_data_label_4
	ui->screen_data_label_4 = lv_label_create(ui->screen_data_tabview_data_tab_2);
	lv_label_set_text(ui->screen_data_label_4, "P:");
	lv_label_set_long_mode(ui->screen_data_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_4, 2, 14);
	lv_obj_set_size(ui->screen_data_label_4, 40, 22);

	//Write style for screen_data_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_5
	ui->screen_data_label_5 = lv_label_create(ui->screen_data_tabview_data_tab_2);
	lv_label_set_text(ui->screen_data_label_5, "I :");
	lv_label_set_long_mode(ui->screen_data_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_5, 2, 68);
	lv_obj_set_size(ui->screen_data_label_5, 40, 22);

	//Write style for screen_data_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_6
	ui->screen_data_label_6 = lv_label_create(ui->screen_data_tabview_data_tab_2);
	lv_label_set_text(ui->screen_data_label_6, "D:");
	lv_label_set_long_mode(ui->screen_data_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_6, 1, 118);
	lv_obj_set_size(ui->screen_data_label_6, 40, 22);

	//Write style for screen_data_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_stand_p
	ui->screen_data_spinbox_stand_p = lv_spinbox_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_p, 93, 2);
	lv_obj_set_width(ui->screen_data_spinbox_stand_p, 76);
	lv_obj_set_height(ui->screen_data_spinbox_stand_p, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_stand_p, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_stand_p, -99999, 99999);
	lv_coord_t screen_data_spinbox_stand_p_h = lv_obj_get_height(ui->screen_data_spinbox_stand_p);
	ui->screen_data_spinbox_stand_p_btn = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_p_btn, screen_data_spinbox_stand_p_h, screen_data_spinbox_stand_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_p_btn, ui->screen_data_spinbox_stand_p, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_p_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_p_btn, lv_screen_data_spinbox_stand_p_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_stand_p_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_p_btn_minus, screen_data_spinbox_stand_p_h, screen_data_spinbox_stand_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_p_btn_minus, ui->screen_data_spinbox_stand_p, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_p_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_p_btn_minus, lv_screen_data_spinbox_stand_p_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_p, 93, 2);

	//Write style for screen_data_spinbox_stand_p, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_p, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_stand_p, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_stand_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_stand_p, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_stand_p, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_stand_p, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_stand_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_stand_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_stand_p, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_p, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_p, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_stand_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_stand_p, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_stand_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_stand_p, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_p, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_p, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_p, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_p, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_stand_p_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_stand_p_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_stand_p_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_stand_p_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_stand_p_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_stand_p_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_stand_p_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_stand_p_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_stand_p_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_stand_p_btn, &style_screen_data_spinbox_stand_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_stand_p_btn_minus, &style_screen_data_spinbox_stand_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_stand_i
	ui->screen_data_spinbox_stand_i = lv_spinbox_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_i, 93, 56);
	lv_obj_set_width(ui->screen_data_spinbox_stand_i, 76);
	lv_obj_set_height(ui->screen_data_spinbox_stand_i, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_stand_i, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_stand_i, -99999, 99999);
	lv_coord_t screen_data_spinbox_stand_i_h = lv_obj_get_height(ui->screen_data_spinbox_stand_i);
	ui->screen_data_spinbox_stand_i_btn = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_i_btn, screen_data_spinbox_stand_i_h, screen_data_spinbox_stand_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_i_btn, ui->screen_data_spinbox_stand_i, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_i_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_i_btn, lv_screen_data_spinbox_stand_i_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_stand_i_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_i_btn_minus, screen_data_spinbox_stand_i_h, screen_data_spinbox_stand_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_i_btn_minus, ui->screen_data_spinbox_stand_i, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_i_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_i_btn_minus, lv_screen_data_spinbox_stand_i_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_i, 93, 56);

	//Write style for screen_data_spinbox_stand_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_stand_i, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_stand_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_stand_i, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_stand_i, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_stand_i, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_stand_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_stand_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_stand_i, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_i, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_i, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_stand_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_stand_i, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_stand_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_stand_i, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_i, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_i, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_i, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_i, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_stand_i_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_stand_i_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_stand_i_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_stand_i_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_stand_i_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_stand_i_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_stand_i_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_stand_i_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_stand_i_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_stand_i_btn, &style_screen_data_spinbox_stand_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_stand_i_btn_minus, &style_screen_data_spinbox_stand_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_stand_d
	ui->screen_data_spinbox_stand_d = lv_spinbox_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_d, 93, 108);
	lv_obj_set_width(ui->screen_data_spinbox_stand_d, 76);
	lv_obj_set_height(ui->screen_data_spinbox_stand_d, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_stand_d, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_stand_d, -99999, 99999);
	lv_coord_t screen_data_spinbox_stand_d_h = lv_obj_get_height(ui->screen_data_spinbox_stand_d);
	ui->screen_data_spinbox_stand_d_btn = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_d_btn, screen_data_spinbox_stand_d_h, screen_data_spinbox_stand_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_d_btn, ui->screen_data_spinbox_stand_d, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_d_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_d_btn, lv_screen_data_spinbox_stand_d_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_stand_d_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_set_size(ui->screen_data_spinbox_stand_d_btn_minus, screen_data_spinbox_stand_d_h, screen_data_spinbox_stand_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_stand_d_btn_minus, ui->screen_data_spinbox_stand_d, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_stand_d_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_stand_d_btn_minus, lv_screen_data_spinbox_stand_d_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_stand_d, 93, 108);

	//Write style for screen_data_spinbox_stand_d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_d, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_stand_d, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_stand_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_stand_d, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_stand_d, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_stand_d, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_stand_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_stand_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_stand_d, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_d, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_d, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_stand_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_stand_d, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_stand_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_stand_d, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_stand_d, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_stand_d, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_stand_d, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_stand_d, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_stand_d_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_stand_d_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_stand_d_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_stand_d_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_stand_d_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_stand_d_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_stand_d_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_stand_d_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_stand_d_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_stand_d_btn, &style_screen_data_spinbox_stand_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_stand_d_btn_minus, &style_screen_data_spinbox_stand_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_img_2
	ui->screen_data_img_2 = lv_img_create(ui->screen_data_tabview_data_tab_2);
	lv_obj_add_flag(ui->screen_data_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_data_img_2, &_stand_16_alpha_16x16);
	lv_img_set_pivot(ui->screen_data_img_2, 50,50);
	lv_img_set_angle(ui->screen_data_img_2, -20);
	lv_obj_set_pos(ui->screen_data_img_2, -8, 2);
	lv_obj_set_size(ui->screen_data_img_2, 16, 16);

	//Write style for screen_data_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_data_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes 转向环
	ui->screen_data_tabview_data_tab_3 = lv_tabview_add_tab(ui->screen_data_tabview_data,"转向环");
	lv_obj_t * screen_data_tabview_data_tab_3_label = lv_label_create(ui->screen_data_tabview_data_tab_3);
	lv_label_set_text(screen_data_tabview_data_tab_3_label, "");

	//Write codes screen_data_label_7
	ui->screen_data_label_7 = lv_label_create(ui->screen_data_tabview_data_tab_3);
	lv_label_set_text(ui->screen_data_label_7, "P:");
	lv_label_set_long_mode(ui->screen_data_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_7, 2, 14);
	lv_obj_set_size(ui->screen_data_label_7, 40, 22);

	//Write style for screen_data_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_8
	ui->screen_data_label_8 = lv_label_create(ui->screen_data_tabview_data_tab_3);
	lv_label_set_text(ui->screen_data_label_8, "I :");
	lv_label_set_long_mode(ui->screen_data_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_8, 2, 68);
	lv_obj_set_size(ui->screen_data_label_8, 40, 22);

	//Write style for screen_data_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_9
	ui->screen_data_label_9 = lv_label_create(ui->screen_data_tabview_data_tab_3);
	lv_label_set_text(ui->screen_data_label_9, "D:");
	lv_label_set_long_mode(ui->screen_data_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_9, 1, 118);
	lv_obj_set_size(ui->screen_data_label_9, 40, 22);

	//Write style for screen_data_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_turn_p
	ui->screen_data_spinbox_turn_p = lv_spinbox_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_p, 93, 2);
	lv_obj_set_width(ui->screen_data_spinbox_turn_p, 76);
	lv_obj_set_height(ui->screen_data_spinbox_turn_p, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_turn_p, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_turn_p, -99999, 99999);
	lv_coord_t screen_data_spinbox_turn_p_h = lv_obj_get_height(ui->screen_data_spinbox_turn_p);
	ui->screen_data_spinbox_turn_p_btn = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_p_btn, screen_data_spinbox_turn_p_h, screen_data_spinbox_turn_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_p_btn, ui->screen_data_spinbox_turn_p, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_p_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_p_btn, lv_screen_data_spinbox_turn_p_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_turn_p_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_p_btn_minus, screen_data_spinbox_turn_p_h, screen_data_spinbox_turn_p_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_p_btn_minus, ui->screen_data_spinbox_turn_p, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_p_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_p_btn_minus, lv_screen_data_spinbox_turn_p_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_p, 93, 2);

	//Write style for screen_data_spinbox_turn_p, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_p, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_turn_p, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_turn_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_turn_p, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_turn_p, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_turn_p, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_turn_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_turn_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_turn_p, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_p, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_p, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_turn_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_turn_p, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_turn_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_turn_p, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_p, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_p, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_p, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_p, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_turn_p_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_turn_p_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_turn_p_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_turn_p_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_turn_p_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_turn_p_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_turn_p_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_turn_p_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_turn_p_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_turn_p_btn, &style_screen_data_spinbox_turn_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_turn_p_btn_minus, &style_screen_data_spinbox_turn_p_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_turn_i
	ui->screen_data_spinbox_turn_i = lv_spinbox_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_i, 93, 56);
	lv_obj_set_width(ui->screen_data_spinbox_turn_i, 76);
	lv_obj_set_height(ui->screen_data_spinbox_turn_i, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_turn_i, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_turn_i, -99999, 99999);
	lv_coord_t screen_data_spinbox_turn_i_h = lv_obj_get_height(ui->screen_data_spinbox_turn_i);
	ui->screen_data_spinbox_turn_i_btn = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_i_btn, screen_data_spinbox_turn_i_h, screen_data_spinbox_turn_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_i_btn, ui->screen_data_spinbox_turn_i, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_i_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_i_btn, lv_screen_data_spinbox_turn_i_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_turn_i_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_i_btn_minus, screen_data_spinbox_turn_i_h, screen_data_spinbox_turn_i_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_i_btn_minus, ui->screen_data_spinbox_turn_i, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_i_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_i_btn_minus, lv_screen_data_spinbox_turn_i_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_i, 93, 56);

	//Write style for screen_data_spinbox_turn_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_turn_i, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_turn_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_turn_i, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_turn_i, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_turn_i, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_turn_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_turn_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_turn_i, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_i, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_i, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_turn_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_turn_i, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_turn_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_turn_i, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_i, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_i, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_i, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_i, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_turn_i_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_turn_i_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_turn_i_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_turn_i_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_turn_i_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_turn_i_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_turn_i_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_turn_i_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_turn_i_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_turn_i_btn, &style_screen_data_spinbox_turn_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_turn_i_btn_minus, &style_screen_data_spinbox_turn_i_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_spinbox_turn_d
	ui->screen_data_spinbox_turn_d = lv_spinbox_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_d, 93, 108);
	lv_obj_set_width(ui->screen_data_spinbox_turn_d, 76);
	lv_obj_set_height(ui->screen_data_spinbox_turn_d, 40);
	lv_spinbox_set_digit_format(ui->screen_data_spinbox_turn_d, 5, 2);
	lv_spinbox_set_range(ui->screen_data_spinbox_turn_d, -99999, 99999);
	lv_coord_t screen_data_spinbox_turn_d_h = lv_obj_get_height(ui->screen_data_spinbox_turn_d);
	ui->screen_data_spinbox_turn_d_btn = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_d_btn, screen_data_spinbox_turn_d_h, screen_data_spinbox_turn_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_d_btn, ui->screen_data_spinbox_turn_d, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_d_btn, LV_SYMBOL_PLUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_d_btn, lv_screen_data_spinbox_turn_d_increment_event_cb, LV_EVENT_ALL, NULL);
	ui->screen_data_spinbox_turn_d_btn_minus = lv_btn_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_set_size(ui->screen_data_spinbox_turn_d_btn_minus, screen_data_spinbox_turn_d_h, screen_data_spinbox_turn_d_h);
	lv_obj_align_to(ui->screen_data_spinbox_turn_d_btn_minus, ui->screen_data_spinbox_turn_d, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_style_bg_img_src(ui->screen_data_spinbox_turn_d_btn_minus, LV_SYMBOL_MINUS, 0);
	lv_obj_add_event_cb(ui->screen_data_spinbox_turn_d_btn_minus, lv_screen_data_spinbox_turn_d_decrement_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->screen_data_spinbox_turn_d, 93, 108);

	//Write style for screen_data_spinbox_turn_d, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_d, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_spinbox_turn_d, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_spinbox_turn_d, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_spinbox_turn_d, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_spinbox_turn_d, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_spinbox_turn_d, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_spinbox_turn_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_spinbox_turn_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_spinbox_turn_d, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_d, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_d, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_spinbox_turn_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_spinbox_turn_d, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_spinbox_turn_d, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_data_spinbox_turn_d, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_data_spinbox_turn_d, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_spinbox_turn_d, &lv_font_montserratMedium_16, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_spinbox_turn_d, 180, LV_PART_CURSOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_spinbox_turn_d, lv_color_hex(0x098D6B), LV_PART_CURSOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_data_spinbox_turn_d_extra_btns_main_default
	static lv_style_t style_screen_data_spinbox_turn_d_extra_btns_main_default;
	ui_init_style(&style_screen_data_spinbox_turn_d_extra_btns_main_default);
	
	lv_style_set_text_color(&style_screen_data_spinbox_turn_d_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_data_spinbox_turn_d_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_bg_opa(&style_screen_data_spinbox_turn_d_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_data_spinbox_turn_d_extra_btns_main_default, lv_color_hex(0x098D6B));
	lv_style_set_border_width(&style_screen_data_spinbox_turn_d_extra_btns_main_default, 0);
	lv_style_set_radius(&style_screen_data_spinbox_turn_d_extra_btns_main_default, 5);
	lv_obj_add_style(ui->screen_data_spinbox_turn_d_btn, &style_screen_data_spinbox_turn_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_data_spinbox_turn_d_btn_minus, &style_screen_data_spinbox_turn_d_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_img_3
	ui->screen_data_img_3 = lv_img_create(ui->screen_data_tabview_data_tab_3);
	lv_obj_add_flag(ui->screen_data_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_data_img_3, &_turn_16_alpha_16x16);
	lv_img_set_pivot(ui->screen_data_img_3, 50,50);
	lv_img_set_angle(ui->screen_data_img_3, -20);
	lv_obj_set_pos(ui->screen_data_img_3, -8, 2);
	lv_obj_set_size(ui->screen_data_img_3, 16, 16);

	//Write style for screen_data_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_data_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes 陀螺仪
	ui->screen_data_tabview_data_tab_4 = lv_tabview_add_tab(ui->screen_data_tabview_data,"陀螺仪");
	lv_obj_t * screen_data_tabview_data_tab_4_label = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(screen_data_tabview_data_tab_4_label, "");

	//Write codes screen_data_label_roll
	ui->screen_data_label_roll = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_roll, "roll: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_roll, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_roll, 44, 4);
	lv_obj_set_size(ui->screen_data_label_roll, 160, 22);

	//Write style for screen_data_label_roll, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_roll, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_roll, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_roll, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_roll, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_pitch
	ui->screen_data_label_pitch = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_pitch, "pitch: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_pitch, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_pitch, 25, 28);
	lv_obj_set_size(ui->screen_data_label_pitch, 160, 22);

	//Write style for screen_data_label_pitch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_pitch, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_pitch, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_pitch, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_pitch, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_yaw
	ui->screen_data_label_yaw = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_yaw, "yaw: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_yaw, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_yaw, 38, 52);
	lv_obj_set_size(ui->screen_data_label_yaw, 160, 22);

	//Write style for screen_data_label_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_yaw, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_yaw, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_yaw, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_gyrox
	ui->screen_data_label_gyrox = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_gyrox, "gyrox: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_gyrox, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_gyrox, 21, 77);
	lv_obj_set_size(ui->screen_data_label_gyrox, 160, 22);

	//Write style for screen_data_label_gyrox, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_gyrox, lv_color_hex(0xB01A9F), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_gyrox, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_gyrox, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_gyrox, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_gyrox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_gyroy
	ui->screen_data_label_gyroy = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_gyroy, "gyroy: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_gyroy, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_gyroy, 21, 103);
	lv_obj_set_size(ui->screen_data_label_gyroy, 160, 22);

	//Write style for screen_data_label_gyroy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_gyroy, lv_color_hex(0xB01A9F), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_gyroy, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_gyroy, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_gyroy, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_gyroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_gyroz
	ui->screen_data_label_gyroz = lv_label_create(ui->screen_data_tabview_data_tab_4);
	lv_label_set_text(ui->screen_data_label_gyroz, "gyroz: 0.000");
	lv_label_set_long_mode(ui->screen_data_label_gyroz, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_gyroz, 21, 128);
	lv_obj_set_size(ui->screen_data_label_gyroz, 160, 22);

	//Write style for screen_data_label_gyroz, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_gyroz, lv_color_hex(0xB01A9F), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_gyroz, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_gyroz, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_gyroz, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_gyroz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_img_4
	ui->screen_data_img_4 = lv_img_create(ui->screen_data_tabview_data_tab_4);
	lv_obj_add_flag(ui->screen_data_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_data_img_4, &_gyroscope_16_alpha_16x16);
	lv_img_set_pivot(ui->screen_data_img_4, 50,50);
	lv_img_set_angle(ui->screen_data_img_4, -20);
	lv_obj_set_pos(ui->screen_data_img_4, -8, 2);
	lv_obj_set_size(ui->screen_data_img_4, 16, 16);

	//Write style for screen_data_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_data_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes 摇杆
	ui->screen_data_tabview_data_tab_5 = lv_tabview_add_tab(ui->screen_data_tabview_data,"摇杆");
	lv_obj_t * screen_data_tabview_data_tab_5_label = lv_label_create(ui->screen_data_tabview_data_tab_5);
	lv_label_set_text(screen_data_tabview_data_tab_5_label, "");

	//Write codes screen_data_label_x
	ui->screen_data_label_x = lv_label_create(ui->screen_data_tabview_data_tab_5);
	lv_label_set_text(ui->screen_data_label_x, "X: 0");
	lv_label_set_long_mode(ui->screen_data_label_x, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_x, 80, 28);
	lv_obj_set_size(ui->screen_data_label_x, 100, 22);

	//Write style for screen_data_label_x, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_x, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_x, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_x, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_x, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_y
	ui->screen_data_label_y = lv_label_create(ui->screen_data_tabview_data_tab_5);
	lv_label_set_text(ui->screen_data_label_y, "Y: 0");
	lv_label_set_long_mode(ui->screen_data_label_y, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_y, 81, 64);
	lv_obj_set_size(ui->screen_data_label_y, 100, 22);

	//Write style for screen_data_label_y, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_y, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_y, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_y, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_y, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_label_sw
	ui->screen_data_label_sw = lv_label_create(ui->screen_data_tabview_data_tab_5);
	lv_label_set_text(ui->screen_data_label_sw, "SW: 0");
	lv_label_set_long_mode(ui->screen_data_label_sw, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_data_label_sw, 62, 98);
	lv_obj_set_size(ui->screen_data_label_sw, 120, 22);

	//Write style for screen_data_label_sw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_label_sw, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_label_sw, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_data_label_sw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_label_sw, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_label_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_img_5
	ui->screen_data_img_5 = lv_img_create(ui->screen_data_tabview_data_tab_5);
	lv_obj_add_flag(ui->screen_data_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_data_img_5, &_rocker_16_alpha_16x16);
	lv_img_set_pivot(ui->screen_data_img_5, 50,50);
	lv_img_set_angle(ui->screen_data_img_5, -20);
	lv_obj_set_pos(ui->screen_data_img_5, -8, 2);
	lv_obj_set_size(ui->screen_data_img_5, 16, 16);

	//Write style for screen_data_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_data_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_data_btn_reset
	ui->screen_data_btn_reset = lv_btn_create(ui->screen_data);
	ui->screen_data_btn_reset_label = lv_label_create(ui->screen_data_btn_reset);
	lv_label_set_text(ui->screen_data_btn_reset_label, "重置");
	lv_label_set_long_mode(ui->screen_data_btn_reset_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_data_btn_reset_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_data_btn_reset, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_data_btn_reset, 10, 188);
	lv_obj_set_size(ui->screen_data_btn_reset, 80, 40);

	//Write style for screen_data_btn_reset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_data_btn_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_data_btn_reset, lv_color_hex(0x292929), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_data_btn_reset, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_data_btn_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_data_btn_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_data_btn_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_data_btn_reset, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_data_btn_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_data_btn_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_data_btn_reset, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_data_btn_reset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_data);

	
}
