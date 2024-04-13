#ifndef _EXTERN_INC_H
#define _EXTERN_INC_H

#include "user_config.h"
#include <TFT_eSPI.h>
#include "nvs_store.h"
#include "wifi_dev.h"
#include "rocker.h"
#include "http_request.h"

typedef enum
{
  TASK_QUEUE_TYPE_WIFI_SCAN,
  TASK_QUEUE_TYPE_WIFI_CONNECT,
  TASK_QUEUE_TYPE_HTTP_REQUEST,
} task_queue_type_t;

extern TFT_eSPI tft;
extern NvsStore nvs;
extern Wifi_Dev wifi_dev;
extern HttpRequest http_client;
extern Rocker rocker;

static inline void tft_led_set(uint8_t level)
{
  uint8_t pwm = map(level, 1, 10, 100, 255);
  analogWrite(TFT_BL, pwm);
}

static inline void system_reboot()
{
  wifi_dev.wifi_disconnect();
  ESP.restart();
}

static inline float map_float(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void taskQueueAdd(task_queue_type_t queue_type);

#endif