#include "lvgl.h"
#include "gui_user.h"

static const int interval_timer = 100;
static const int interval_gyroscope_update = (500 / interval_timer);
static const int interval_rocker_update = (200 / interval_timer);
static lv_timer_t *timer;
static int timer_count = 0;

static void screen_event_handler(lv_event_t *e);

static void pid_data_update()
{
  req_result_t *result = http_client.request_get_data();

  lv_spinbox_set_value(guider_ui.screen_data_spinbox_vel_p, result->pid_data[0] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_vel_i, result->pid_data[1] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_vel_d, result->pid_data[2] * 1000);

  lv_spinbox_set_value(guider_ui.screen_data_spinbox_stand_p, result->pid_data[3] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_stand_i, result->pid_data[4] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_stand_d, result->pid_data[5] * 1000);

  lv_spinbox_set_value(guider_ui.screen_data_spinbox_turn_p, result->pid_data[6] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_turn_i, result->pid_data[7] * 1000);
  lv_spinbox_set_value(guider_ui.screen_data_spinbox_turn_d, result->pid_data[8] * 1000);
}

static void gyroscope_data_update()
{
  req_result_t *result = http_client.request_get_data();

  lv_label_set_text_fmt(guider_ui.screen_data_label_roll, "roll:%.3f", result->gyroscope[0]);
  lv_label_set_text_fmt(guider_ui.screen_data_label_pitch, "pitch:%.3f", result->gyroscope[1]);
  lv_label_set_text_fmt(guider_ui.screen_data_label_yaw, "yaw:%.3f", result->gyroscope[2]);
  lv_label_set_text_fmt(guider_ui.screen_data_label_gyrox, "gyrox:%.3f", result->gyroscope[3]);
  lv_label_set_text_fmt(guider_ui.screen_data_label_gyroy, "gyroy:%.3f", result->gyroscope[4]);
  lv_label_set_text_fmt(guider_ui.screen_data_label_gyroz, "gyroz:%.3f", result->gyroscope[5]);
}

static void http_request_callback(req_params_t *param)
{
  if (param->command_query_type == COMMAND_QUERY_PID)
  {
    pid_data_update();
  }
  else if (param->command_query_type == COMMAND_QUERY_GYROSCOPE)
  {
    gyroscope_data_update();
  }
}

static void timer_task(lv_timer_t *timer)
{
  int tabview_index = lv_tabview_get_tab_act(guider_ui.screen_data_tabview_data);

  if (timer_count % interval_gyroscope_update == 0)
  {
    // TODO //陀螺仪数据请求
    if (tabview_index == 3)
    {
      if (wifi_dev.wifi_is_conn())
        http_client.request_add(http_client.get_gyroscope_query_param());
    }
  }

  if (timer_count % interval_rocker_update == 0)
  {
    // TODO 摇杆数据更新
    if (tabview_index == 4)
    {
      rocker_data_t *data = rocker.rocker_get_data();
      lv_label_set_text_fmt(guider_ui.screen_data_label_x, "X: %d", data->data_x);
      lv_label_set_text_fmt(guider_ui.screen_data_label_y, "Y: %d", data->data_y);
      lv_label_set_text_fmt(guider_ui.screen_data_label_sw, "SW: %d", data->data_sw);
    }
  }

  if (++timer_count > INT32_MAX)
    timer_count = 0;
}

static void click_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  req_params_t param;

  if (obj == guider_ui.screen_data_btn_back)
  {
    lv_timer_del(timer);
    http_client.request_set_callback(NULL);
    guiGotoPageAnim(PAGE_MAIN);
  }
  else if (obj == guider_ui.screen_data_btn_query)
  {
    // 查询PID数据
    if (wifi_dev.wifi_is_conn())
      http_client.request_add(http_client.get_pid_query_param());
  }
  else if (obj == guider_ui.screen_data_btn_reset)
  {
    // 重置PID数据
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_RESET_PID);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);

    // 查询PID数据
    if (wifi_dev.wifi_is_conn())
      http_client.request_add(http_client.get_pid_query_param());
  }
  // else if (obj == guider_ui.screen_data_btn_save)
  // {
  //   // 保存PID数据
  //   param.api = REQ_API_COMMAND;
  //   param.command_type = COMMAND_TYPE_SET;
  //   sprintf(param.command_data, COMMAND_STORE_PID);

  //   if (wifi_dev.wifi_is_conn())
  //     http_client.request_add(&param);
  // }
  else if (obj == guider_ui.screen_data_spinbox_vel_p_btn_minus || obj == guider_ui.screen_data_spinbox_vel_p_btn)
  {
    // 设置速度环KP
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PVP", lv_spinbox_get_value(guider_ui.screen_data_spinbox_vel_p) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_vel_i_btn_minus || obj == guider_ui.screen_data_spinbox_vel_i_btn)
  {
    // 设置速度环KI
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PVI", lv_spinbox_get_value(guider_ui.screen_data_spinbox_vel_i) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_vel_d_btn_minus || obj == guider_ui.screen_data_spinbox_vel_d_btn)
  {
    // 设置速度环KD
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PVD", lv_spinbox_get_value(guider_ui.screen_data_spinbox_vel_d) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_stand_p_btn_minus || obj == guider_ui.screen_data_spinbox_stand_p_btn)
  {
    // 设置直立环KP
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PSP", lv_spinbox_get_value(guider_ui.screen_data_spinbox_stand_p) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_stand_i_btn_minus || obj == guider_ui.screen_data_spinbox_stand_i_btn)
  {
    // 设置直立环KI
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PSI", lv_spinbox_get_value(guider_ui.screen_data_spinbox_stand_i) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_stand_d_btn_minus || obj == guider_ui.screen_data_spinbox_stand_d_btn)
  {
    // 设置直立环KD
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PSD", lv_spinbox_get_value(guider_ui.screen_data_spinbox_stand_d) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_turn_p_btn_minus || obj == guider_ui.screen_data_spinbox_turn_p_btn)
  {
    // 设置转向环KP
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PTP", lv_spinbox_get_value(guider_ui.screen_data_spinbox_turn_p) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_turn_i_btn_minus || obj == guider_ui.screen_data_spinbox_turn_i_btn)
  {
    // 设置转向环KI
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PTI", lv_spinbox_get_value(guider_ui.screen_data_spinbox_turn_i) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
  }
  else if (obj == guider_ui.screen_data_spinbox_turn_d_btn_minus || obj == guider_ui.screen_data_spinbox_turn_d_btn)
  {
    // 设置转向环KD
    param.api = REQ_API_COMMAND;
    param.command_type = COMMAND_TYPE_SET;
    sprintf(param.command_data, COMMAND_SET_PID, "PTD", lv_spinbox_get_value(guider_ui.screen_data_spinbox_turn_d) / 1000.0f);

    if (wifi_dev.wifi_is_conn())
      http_client.request_add(&param);
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
  default:
    break;
  }
}

void setup_user_screen_data(lv_ui *ui)
{
  timer_count = 0;
  timer = lv_timer_create(timer_task, interval_timer, NULL);

  http_client.request_set_callback(http_request_callback);

  if (wifi_dev.wifi_is_conn())
    http_client.request_add(http_client.get_pid_query_param());

  lv_obj_add_event_cb(ui->screen_data_btn_reset, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_btn_query, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_btn_back, screen_event_handler, LV_EVENT_CLICKED, NULL);
  // lv_obj_add_event_cb(ui->screen_data_btn_save, screen_event_handler, LV_EVENT_CLICKED, NULL);

  // pid velocity
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_p_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_p_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_i_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_i_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_d_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_vel_d_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);

  // pid stand
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_p_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_p_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_i_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_i_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_d_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_stand_d_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);

  // pid steering
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_p_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_p_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_i_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_i_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_d_btn_minus, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_data_spinbox_turn_d_btn, screen_event_handler, LV_EVENT_CLICKED, NULL);
}