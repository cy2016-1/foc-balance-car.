#include "lvgl.h"
#include "gui_user.h"
#include "img_converters.h"

#define FRAME_SIZE (GUI_WIDTH * GUI_HEIGHT * 2)

static const int interval_timer = 100;
static const int interval_data_update = (200 / interval_timer);
static const int interval_send_update = (400 / interval_timer);
static lv_timer_t *timer;
static int timer_count = 0;

static uint8_t *stream_img_buff;

static lv_img_dsc_t jpeg_dsc;

float old_velocity, old_steering;

static void http_stream_callback(char *buff, size_t len)
{
  // SERIAL_ECHO_F("fram len: %d\n", len);

  if (NULL == guider_ui.screen_camera || wifi_dev.wifi_is_conn() == false)
    return;

  if (is_jpg((uint8_t *)buff))
  {
    if (NULL == stream_img_buff)
      return;

    if (jpg2rgb565((uint8_t *)buff, len, stream_img_buff, JPG_SCALE_NONE))
    {
      for (int i = 0; i < FRAME_SIZE; i += 2)
      {
        if (NULL == stream_img_buff || wifi_dev.wifi_is_conn() == false)
          return;
        uint8_t temp = stream_img_buff[i];
        stream_img_buff[i] = stream_img_buff[i + 1];
        stream_img_buff[i + 1] = temp;
      }

      jpeg_dsc.data_size = FRAME_SIZE;
      jpeg_dsc.data = stream_img_buff;
      lv_img_set_src(guider_ui.screen_camera_img_cam, &jpeg_dsc);
    }
  }
}

static void timer_task(lv_timer_t *timer)
{
  if (timer_count % interval_data_update == 0)
  {
    lv_label_set_text_fmt(guider_ui.screen_camera_label_velocity, "%.1f", rocker.rocker_get_velocity());
    lv_label_set_text_fmt(guider_ui.screen_camera_label_turn, "%.1f", rocker.rocker_get_steering());
  }

  if (timer_count % interval_send_update == 0)
  {
    req_params_t req_param;

    // 设置速度
    if (old_velocity != rocker.rocker_get_velocity())
    {
      req_param.api = REQ_API_COMMAND;
      req_param.command_type = COMMAND_TYPE_SET;
      sprintf(req_param.command_data, COMMAND_SET_VELOCITY, rocker.rocker_get_velocity());
      if (wifi_dev.wifi_is_conn())
        http_client.request_add(&req_param);

      old_velocity = rocker.rocker_get_velocity();
    }

    // 设置转向
    if (old_steering != rocker.rocker_get_steering())
    {
      memset(&req_param, 0x0, sizeof(req_params_t));
      req_param.api = REQ_API_COMMAND;
      req_param.command_type = COMMAND_TYPE_SET;
      sprintf(req_param.command_data, COMMAND_SET_TURN, rocker.rocker_get_steering());
      if (wifi_dev.wifi_is_conn())
        http_client.request_add(&req_param);

      old_steering = rocker.rocker_get_steering();
    }
  }

  if (++timer_count > INT32_MAX)
    timer_count = 0;
}

static void click_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  if (obj == guider_ui.screen_camera_btn_back)
  {
    lv_timer_del(timer);

    heap_caps_free(stream_img_buff);
    stream_img_buff = NULL;

    http_client.stream_stop();
    http_client.stream_set_callback(NULL);

    guiGotoPage(PAGE_MAIN);
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

void setup_user_screen_camera(lv_ui *ui)
{
  jpeg_dsc.header.always_zero = 0;
  jpeg_dsc.header.cf = LV_IMG_CF_TRUE_COLOR;
  jpeg_dsc.header.h = GUI_HEIGHT;
  jpeg_dsc.header.reserved = 0;
  jpeg_dsc.header.w = GUI_WIDTH;

  timer_count = 0;
  timer = lv_timer_create(timer_task, interval_timer, NULL);

  stream_img_buff = (uint8_t *)heap_caps_malloc(FRAME_SIZE, MALLOC_CAP_SPIRAM);
  if (NULL == stream_img_buff)
    SERIAL_ECHO_LN("stream buff malloc failed!");

  // 摄像头配置
  req_params_t req_param;

  // 摄像头分辨率
  req_param.api = REQ_API_CONTROL;
  req_param.control_var = REQ_FRAME_SIZE;
  req_param.control_val = FRAME_SIZE_QVGA;
  if (wifi_dev.wifi_is_conn())
    http_client.request_add(&req_param);

#if 0
  // 摄像头水平翻转
  req_param.api = REQ_API_CONTROL;
  req_param.control_var = REQ_H_MIRROR;
  req_param.control_val = H_MIRROR_ON;
  if (wifi_dev.wifi_is_conn())
    http_client.request_add(&req_param);

  // 摄像头垂直翻转
  req_param.api = REQ_API_CONTROL;
  req_param.control_var = REQ_V_FLIP;
  req_param.control_val = V_FLIP_OFF;
  if (wifi_dev.wifi_is_conn())
    http_client.request_add(&req_param);
#endif

  // 打开视频流
  req_param.api = REQ_API_STREAM;
  if (wifi_dev.wifi_is_conn())
    http_client.request_add(&req_param);

  http_client.stream_set_callback(http_stream_callback);

  lv_obj_add_event_cb(ui->screen_camera_btn_back, screen_event_handler, LV_EVENT_CLICKED, NULL);
}