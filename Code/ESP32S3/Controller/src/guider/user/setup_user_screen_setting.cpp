#include "lvgl.h"
#include "gui_user.h"

static lv_anim_timeline_t *anim_timeline = NULL;
static uint8_t anim_ready_count;
static bool src_exit_flag;

static void keyboard_ready_cb(lv_obj_t *obj_com, const char *str)
{
  lv_obj_t *parent = lv_obj_get_parent(obj_com);

  if (NULL != str)
  {
    lv_textarea_set_text(guider_ui.screen_setting_ta_passwd, str);
  }
}

static void wifi_scan_callback(int num)
{
  lv_obj_add_flag(guider_ui.screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);

  for (int i = 0; i < num; i++)
  {
    lv_dropdown_add_option(guider_ui.screen_setting_ddlist_ssid, wifi_dev.wifi_get_ssid(i), i);
  }
}

static void wifi_status_callback()
{
  lv_obj_add_flag(guider_ui.screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);

  if (wifi_dev.wifi_is_conn())
  {
    lv_obj_clear_flag(guider_ui.screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(guider_ui.screen_setting_label_state, "已连接");
    lv_label_set_text(lv_obj_get_child(guider_ui.screen_setting_btn_connect, 0), "断开");

    lv_label_set_text(guider_ui.screen_setting_label_ip_addr, wifi_dev.wifi_get_ip());

    // 保存连接信息
    if (strcmp(nvs.nvs_sys_data.wifi_ssid, wifi_dev.wifi_get_conn_ssid()) != 0)
    {
      memcpy(nvs.nvs_sys_data.wifi_ssid, wifi_dev.wifi_get_conn_ssid(), sizeof(nvs.nvs_sys_data.wifi_ssid));
      nvs.write(NVS_NAMESPACE_BLOB_SYSTEM);
    }
    if (strcmp(nvs.nvs_sys_data.wifi_passwd, wifi_dev.wifi_get_conn_passwd()) != 0)
    {
      memcpy(nvs.nvs_sys_data.wifi_passwd, wifi_dev.wifi_get_conn_passwd(), sizeof(nvs.nvs_sys_data.wifi_passwd));
      nvs.write(NVS_NAMESPACE_BLOB_SYSTEM);
    }
  }
  else
  {
    lv_label_set_text(lv_obj_get_child(guider_ui.screen_setting_btn_connect, 0), "连接");
    lv_label_set_text(guider_ui.screen_setting_label_ip_addr, "0.0.0.0");
  }
}

static void anim_ready_callback(lv_anim_t *a)
{
  anim_ready_count++;
  if (anim_ready_count >= 2)
  {
    if (anim_timeline)
    {
      lv_anim_timeline_del(anim_timeline);
      anim_timeline = NULL;
    }

    if (src_exit_flag)
    {
      guiGotoPage(PAGE_MAIN);
    }

    anim_ready_count = 0;
  }
}

void src_setting_load_exit()
{
  lv_anim_t anim;
  lv_anim_init(&anim);

  int cont_top_x_start, cont_top_x_end;
  int cont_bottom_x_start, cont_bottom_x_end;

  if (anim_timeline == NULL)
    anim_timeline = lv_anim_timeline_create();

  if (src_exit_flag)
  {
    // 退出
    cont_top_x_start = 5;
    cont_top_x_end = 320;
    cont_bottom_x_start = 5;
    cont_bottom_x_end = -320;
  }
  else
  {
    // 加载
    cont_top_x_start = 320;
    cont_top_x_end = 5;
    cont_bottom_x_start = -320;
    cont_bottom_x_end = 5;
  }

  ANIM_LINE_ADD(&anim, anim_x_cb, lv_anim_path_overshoot, anim_ready_callback, 250, 0, 0, guider_ui.screen_setting_cont_top, cont_top_x_start, cont_top_x_end, 0);
  lv_anim_timeline_add(anim_timeline, 0, &anim);
  ANIM_LINE_ADD(&anim, anim_x_cb, lv_anim_path_overshoot, anim_ready_callback, 250, 0, 0, guider_ui.screen_setting_cont_bottom, cont_bottom_x_start, cont_bottom_x_end, 0);
  lv_anim_timeline_add(anim_timeline, 0, &anim);

  lv_anim_timeline_start(anim_timeline);
}

static void click_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  if (obj == guider_ui.screen_setting_btn_back)
  {
    src_exit_flag = true;
    wifi_dev.wifi_scan_set_cb(NULL);
    wifi_dev.wifi_status_set_cb(NULL);
    src_setting_load_exit();
  }
  else if (obj == guider_ui.screen_setting_btn_reset)
  {
    // 重置系统设置
    nvs.reset(NVS_NAMESPACE_BLOB_SYSTEM);
    system_reboot();
  }
  else if (obj == guider_ui.screen_setting_btn_search)
  {
    // 搜索wifi
    if (wifi_dev.wifi_is_scan())
      return;

    if (lv_dropdown_get_option_cnt(guider_ui.screen_setting_ddlist_ssid) > 0)
    {
      lv_dropdown_clear_options(guider_ui.screen_setting_ddlist_ssid);
    }

    lv_obj_clear_flag(guider_ui.screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(guider_ui.screen_setting_label_state, "搜索中...");
    taskQueueAdd(TASK_QUEUE_TYPE_WIFI_SCAN);
  }
  else if (obj == guider_ui.screen_setting_ta_passwd)
  {
    // 输入密码
    keyboard_helper_t kb_helper = {
        .parent = guider_ui.screen_setting,
        .ready_handle = keyboard_ready_cb,
        .title_txt = "Input Password",
        .content_txt = lv_textarea_get_text(guider_ui.screen_setting_ta_passwd),
        .one_line = STATE_ON};

    keyboard_create(&kb_helper);
  }
  else if (obj == guider_ui.screen_setting_btn_connect)
  {
    // 连接wifi
    if (wifi_dev.wifi_is_scan())
      return; // wifi搜索中禁止连接

    if (wifi_dev.wifi_is_conn())
    {
      // 断开
      wifi_dev.wifi_disconnect();
    }
    else
    {
      char ssid[32];
      lv_dropdown_get_selected_str(guider_ui.screen_setting_ddlist_ssid, ssid, sizeof(ssid));

      if (strlen(ssid) == 0)
        return;

      lv_obj_clear_flag(guider_ui.screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(guider_ui.screen_setting_label_state, "连接中...");

      wifi_dev.wifi_set_info(ssid, lv_textarea_get_text(guider_ui.screen_setting_ta_passwd));
      taskQueueAdd(TASK_QUEUE_TYPE_WIFI_CONNECT);
    }
  }
}

static void value_changed_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  if (obj == guider_ui.screen_setting_slider_led)
  {
    uint8_t val = lv_slider_get_value(obj);
    tft_led_set(val);

    if (val != nvs.nvs_sys_data.lcd_backlight)
    {
      nvs.nvs_sys_data.lcd_backlight = val;
      nvs.write(NVS_NAMESPACE_BLOB_SYSTEM);
    }
  }
}

static void screen_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  switch (code)
  {
  case LV_EVENT_CLICKED:
  {
    click_event_handler(e);
    break;
  }
  case LV_EVENT_VALUE_CHANGED:
  {
    value_changed_event_handler(e);
    break;
  }
  default:
    break;
  }
}

void setup_user_screen_setting(lv_ui *ui)
{
  src_exit_flag = false;
  anim_ready_count = 0;

  wifi_dev.wifi_scan_set_cb(wifi_scan_callback);
  wifi_dev.wifi_status_set_cb(wifi_status_callback);

  lv_obj_clear_flag(ui->screen_setting, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_add_event_cb(ui->screen_setting_btn_back, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_setting_btn_search, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_setting_btn_connect, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_setting_ta_passwd, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_setting_btn_reset, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_setting_slider_led, screen_event_handler, LV_EVENT_VALUE_CHANGED, NULL);

  lv_dropdown_set_options(guider_ui.screen_setting_ddlist_ssid, nvs.nvs_sys_data.wifi_ssid);
  lv_textarea_set_text(guider_ui.screen_setting_ta_passwd, nvs.nvs_sys_data.wifi_passwd);

  lv_slider_set_value(ui->screen_setting_slider_led, nvs.nvs_sys_data.lcd_backlight, LV_ANIM_ON);

  if (wifi_dev.wifi_is_scan())
  {
    lv_obj_clear_flag(ui->screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui->screen_setting_label_state, "搜索中...");
  }

  if (wifi_dev.wifi_is_conn())
  {
    lv_obj_clear_flag(ui->screen_setting_label_state, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui->screen_setting_label_state, "已连接");
    lv_label_set_text(lv_obj_get_child(ui->screen_setting_btn_connect, 0), "断开");
    lv_label_set_text(ui->screen_setting_label_ip_addr, wifi_dev.wifi_get_ip());
  }
  else
  {
    lv_label_set_text(lv_obj_get_child(ui->screen_setting_btn_connect, 0), "连接");
  }

  src_setting_load_exit();
}