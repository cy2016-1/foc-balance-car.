#include "http_request.h"

HttpRequest::HttpRequest()
{
  if (queue_handle == NULL)
    queue_handle = xQueueCreate(16, sizeof(req_params_t));
}

HttpRequest::~HttpRequest()
{
}

void HttpRequest::request_result_analyze(req_params_t *param)
{
  int index;
  String sub_s;

  if (req_result.length() <= 0)
    return;

  SERIAL_ECHO_LN(req_result.c_str());

  index = req_result.indexOf(' ');
  sub_s = req_result.substring(0, index);
  req_result = req_result.substring(index + 1, req_result.length());

  if (sub_s.equals("P"))
  {
    // 解析PID
    for (int i = 0; i < sizeof(req_result_data.pid_data); i++)
    {
      index = req_result.indexOf(' ');

      if (index > 0)
      {
        sub_s = req_result.substring(0, index);
        req_result = req_result.substring(index + 1, req_result.length());

        req_result_data.pid_data[i] = sub_s.toFloat();
      }
      else
      {
        req_result.trim();
        req_result_data.pid_data[i] = req_result.toFloat();
        break;
      }
    }
  }
  else if (sub_s.equals("G"))
  {
    // 解析陀螺仪
    for (int i = 0; i < sizeof(req_result_data.gyroscope); i++)
    {
      index = req_result.indexOf(' ');

      if (index > 0)
      {
        sub_s = req_result.substring(0, index);
        req_result = req_result.substring(index + 1, req_result.length());

        req_result_data.gyroscope[i] = sub_s.toFloat();
      }
      else
      {
        req_result.trim();
        req_result_data.gyroscope[i] = req_result.toFloat();
        break;
      }
    }
  }
  else if (sub_s.equals("V"))
  {
    // 解析速度
    req_result.trim();
    req_result_data.velocity = req_result.toFloat();
  }
  else if (sub_s.equals("T"))
  {
    // 解析转向
    req_result.trim();
    req_result_data.steering = req_result.toFloat();
  }
}

void HttpRequest::request_task(req_params_t *param)
{
  memset(req_url, 0x0, sizeof(req_url));

  if (param->api == REQ_API_CONTROL)
  {
    sprintf(req_url, CAMERA_CONTROL_API, CAMERA_SERVER_HOST, req_var[param->control_var], param->control_val);
  }
  else if (param->api == REQ_API_COMMAND)
  {
    sprintf(req_url, CAMERA_COMMAND_API, CAMERA_SERVER_HOST, param->command_type, param->command_data);
  }

  SERIAL_ECHO_LN(req_url);
  // return;

  http.begin(req_url);
  http.setTimeout(1000);

  int httpCode = http.GET();

  if (httpCode > 0)
  {
    if (httpCode == HTTP_CODE_OK)
    {
      req_result = http.getString();

      // 解析数据
      request_result_analyze(param);

      if (NULL != req_cb)
      {
        req_cb(param);
      }
    }
  }

  http.end();
}

void HttpRequest::stream_handler()
{
  for (;;)
  {
    if (stream_state_flag == false)
    {
      vTaskDelay(100);
      continue;
    }

    sprintf(req_url, CAMERA_STREAM_API, CAMERA_SERVER_HOST);
    SERIAL_ECHO_LN(req_url);

    HTTPClient http;
    char buff[256] = {0}; // 数据缓冲区
    char *frame_buff;     // 帧缓冲区

    http.begin(req_url);
    http.setTimeout(1000);

    int httpCode = http.GET();
    if (httpCode > 0)
    {
      if (httpCode == HTTP_CODE_OK)
      {
        WiFiClient *stream = http.getStreamPtr();
        stream->setTimeout(1000);
        while (stream_state_flag && http.connected())
        {
          size_t size = stream->available();
          // SERIAL_ECHO_F("size: %d\n", size);

          int content_len = 0;
          int read_len = 0;
          memset(buff, 0x0, sizeof(buff));

          stream->readBytes(buff, sizeof(buff));
          if (strstr(buff, PART_BOUNDARY) && strchr(buff, '\n'))
          {
            // SERIAL_ECHO_LN(buff);

            char *ret = strstr(buff, PART_CONTENT_LENGTH);
            if (NULL == ret)
              continue;

            char *end = strchr(ret, '\n');
            if (NULL == end)
              continue;

            char *len_index = (ret + strlen(PART_CONTENT_LENGTH));
            int len = (end - len_index);
            if (len <= 0)
              continue;

            char data_len[len];
            memcpy(data_len, len_index, len);

            content_len = atoi(data_len);
            frame_buff = new char[content_len];
            // SERIAL_ECHO_F("content len: %d\n", content_len);

            if (NULL == frame_buff)
              continue;
          }

          if (content_len > 0)
          {
            char *end = strrchr(buff, '\n');
            int head_len = end - buff;
            read_len = sizeof(buff) - head_len - 1;

            // SERIAL_ECHO_LN(end);
            // SERIAL_ECHO_F("first read: %d\n", read_len);

            // 拷贝读取的数据
            memcpy(frame_buff, end+1, read_len);
            // 读取一帧剩余数据
            while (stream->available() && read_len < content_len)
            {
              int c = stream->readBytes(buff, (read_len + sizeof(buff) > content_len ? (content_len - read_len) : sizeof(buff)));
              memcpy(frame_buff + read_len, buff, c);
              read_len += c;
              // SERIAL_ECHO_F("read buff: %d\n", c);
            }

            // SERIAL_ECHO_F("total read: %d\n", read_len);
            // SERIAL_ECHO_LN("--------------------------------");

            // 显示回调
            if(NULL != stream_cb)
              stream_cb(frame_buff, read_len);
            // 释放内存
            delete []frame_buff;
          }

          vTaskDelay(1);
        }
      }
    }

    SERIAL_ECHO_LN("http stream closed!");
    http.end();
  }
}

void HttpRequest::request()
{
  BaseType_t xReturn = pdFALSE;
  req_params_t req_param;

  xReturn = xQueueReceive(queue_handle, &req_param, portMAX_DELAY);
  if (xReturn == pdTRUE)
  {
    if (req_param.api == REQ_API_STREAM)
    {
      // 视频流
      stream_state_flag = true;
      memcpy(&req_param_stream, &req_param, sizeof(req_params_t));
    }
    else
    {
      request_task(&req_param);
    }
  }
}

void HttpRequest::request_set_callback(request_callback cb)
{
  req_cb = cb;
}

void HttpRequest::stream_set_callback(stream_callback cb)
{
  stream_cb = cb;
}