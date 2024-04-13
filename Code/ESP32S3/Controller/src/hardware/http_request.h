#pragma once

/********************************
设置命令格式
设置速度: M0 V5
设置转向: M0 T5
设置速度PID: M0 PVP0.01/I0.01/D0.01
设置直立PID: M0 PSP0.01/I0.01/D0.01
设置转向PID: M0 PTP0.01/I0.01/D0.01
保存PID数据: M0 SP
重置PID数据: M0 RP

查询命令格式
查询PID    : M0 UP
查询陀螺仪  : M0 UG
查询速度    : M0 UV
查询转向    : M0 UT

查询数据格式
上传PID    : P 0 0 0 0 0 0 0 0 0 (三个一组，分别对应速度，直立，转向PID)
上传陀螺仪  : G 0 0 0 0 0 0 (对应roll pitch yaw x_gyro y_gyro z_gyro)
上传速度   : V 0
上传转向   : T 0
*********************************/

#include <Arduino.h>
#include <HTTPClient.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "user_config.h"

#define PART_CONTENT_END_TAG "\r\n\r\n"
#define PART_CONTENT_LENGTH "Content-Length: "
#define PART_BOUNDARY "123456789000000000000987654321"

typedef enum
{
  REQ_API_CONTROL,
  REQ_API_STREAM,
  REQ_API_ROCKER,
  REQ_API_COMMAND,
  REQ_API_MAX,
} req_api_t;

typedef enum
{
  REQ_FRAME_SIZE,
  REQ_SPEECIAL_EFFECT,
  REQ_H_MIRROR,
  REQ_V_FLIP,
  REQ_LED_INTENSITY,
  REQ_COMMAND_TYPE,
  REQ_COMMAND_CONTENT,
  REQ_VAR_MAX,
} req_var_t;

typedef enum
{
  COMMAND_TYPE_NONE,
  COMMAND_TYPE_SET,
  COMMAND_TYPE_QUERY,
} command_type_t;

typedef enum
{
  COMMAND_QUERY_NONE,
  COMMAND_QUERY_PID,
  COMMAND_QUERY_GYROSCOPE,
  COMMAND_QUERY_VELOCITY,
  COMMAND_QUERY_STERRING,
} command_query_type_t;

typedef enum
{
  FRAME_SIZE_96_96 = 0, // 96X96
  FRAME_SIZE_QQVGA,     // 160X120
  FRAME_SIZE_QCIF,      // 176X144
  FRAME_SIZE_HQVGA,     // 240X176
  FRAME_SIZE_240_2,     // 240X240
  FRAME_SIZE_QVGA,      // 320X240
  FRAME_SIZE_CIF,       // 320X240
  FRAME_SIZE_HVGA,      // 480X320
  FRAME_SIZE_VGA,       // 640X480
  FRAME_SIZE_SVGA,      // 800X600
  FRAME_SIZE_XGA,       // 1024X768
  FRAME_SIZE_HD,        // 1280X720
  FRAME_SIZE_SXGA,      // 1280X1024
  FRAME_SIZE_UXGA,      // 1600X1200
} camera_framesize_t;

typedef enum
{
  H_MIRROR_OFF = 0,
  H_MIRROR_ON,
} camera_hmirror_t;

typedef enum
{
  V_FLIP_OFF = 0,
  V_FLIP_ON,
} camera_vflip_t;

typedef enum
{
  SE_NO = 0,
  SE_NEGATIVE,
  SE_GRAY_SCALE,
  SE_RED_TINT,
  SE_GREEN_TINT,
  SE_BLUE_TINT,
  SE_SEPIA,
} camera_se_t; // Special Effect

typedef struct
{
  void *user_data;
  req_api_t api;
  req_var_t control_var;
  uint8_t control_val;
  command_query_type_t command_query_type;
  command_type_t command_type;
  char command_data[16];
} req_params_t; // 请求结构体

typedef struct
{
  // vel,stand,turn
  float pid_data[9];

  // roll,pitch,yaw,gyrox,gyroy,gyroz
  float gyroscope[6];

  float velocity;
  float steering;
} req_result_t;

typedef void (*request_callback)(req_params_t *param);
typedef void (*stream_callback)(char *buff, size_t len);

class HttpRequest
{
private:
  HTTPClient http;

  char req_url[128];
  String req_result;
  req_result_t req_result_data;
  req_params_t req_param;
  req_params_t req_param_stream;

  bool stream_state_flag;

  request_callback req_cb;
  stream_callback stream_cb;

  QueueHandle_t queue_handle = NULL;

  void request_task(req_params_t *param);
  void request_result_analyze(req_params_t *param);

public:
  HttpRequest();
  ~HttpRequest();
  void request_add(req_params_t *param) { xQueueSendToBack(queue_handle, param, 0); };
  void request();
  void request_set_callback(request_callback cb);

  const char *request_get_result() { return req_result.c_str(); }
  req_result_t *request_get_data() { return &req_result_data; }

  void stream_handler();
  void stream_run() { stream_state_flag = true; }
  void stream_stop() { stream_state_flag = false; }
  void stream_set_callback(stream_callback cb);
  bool stream_is_run() { return stream_state_flag; }

  req_params_t *get_pid_query_param()
  {
    memset(&req_param, 0x0, sizeof(req_params_t));

    req_param.api = REQ_API_COMMAND;
    req_param.command_type = COMMAND_TYPE_QUERY;
    req_param.command_query_type = COMMAND_QUERY_PID;
    sprintf(req_param.command_data, COMMAND_UPLOAD_PID);

    return &req_param;
  }

  req_params_t *get_gyroscope_query_param()
  {
    memset(&req_param, 0x0, sizeof(req_params_t));

    req_param.api = REQ_API_COMMAND;
    req_param.command_type = COMMAND_TYPE_QUERY;
    req_param.command_query_type = COMMAND_QUERY_GYROSCOPE;
    sprintf(req_param.command_data, COMMAND_UPLOAD_GYROSCOPEDATA);

    return &req_param;
  }

  req_params_t *get_velocity_query_param()
  {
    memset(&req_param, 0x0, sizeof(req_params_t));

    req_param.api = REQ_API_COMMAND;
    req_param.command_type = COMMAND_TYPE_QUERY;
    req_param.command_query_type = COMMAND_QUERY_VELOCITY;
    sprintf(req_param.command_data, COMMAND_UPLOAD_VELOCITY);

    return &req_param;
  }

  req_params_t *get_steering_query_param()
  {
    memset(&req_param, 0x0, sizeof(req_params_t));

    req_param.api = REQ_API_COMMAND;
    req_param.command_type = COMMAND_TYPE_QUERY;
    req_param.command_query_type = COMMAND_QUERY_STERRING;
    sprintf(req_param.command_data, COMMAND_UPLOAD_TURN);

    return &req_param;
  }

  const char *req_api[REQ_API_MAX] = {
      "control",
      "stream",
      "rocker",
      "command",
  };

  const char *req_var[REQ_VAR_MAX] = {
      "framesize",
      "special_effect",
      "hmirror",
      "vflip",
      "led_intensity",
      "type",
      "cmd",
  };
};
