#pragma once

#include <Arduino.h>
#include <Preferences.h>
#include "touch_cal.h"
#include "user_config.h"

#define NVS_NAMESPACE_BLOB_SYSTEM "blob_system"

typedef struct
{
  uint8_t device_id[4];                      // 设备ID
  char wifi_ssid[32];                        // WIFI名字
  char wifi_passwd[32];                      // WIFI密码
  uint16_t touch_caldata[TOUCH_CALDATA_LEN]; // 触摸屏校准数据
  uint8_t lcd_backlight : 4;                 // 屏幕亮度(1-10)
  uint8_t lcd_touch_calibrate : 1;           // 触屏校准标志
} nvs_blob_system_t;

class NvsStore
{
private:
  void def_init(const char *space);
  static uint32_t read_chip_id();

  Preferences prefs;
  size_t space_len;
  esp_err_t err;

public:
  NvsStore(){};
  ~NvsStore(){};

  void init();
  esp_err_t read(const char *space);
  esp_err_t write(const char *space);
  void reset(const char *space);

  nvs_blob_system_t nvs_sys_data;
};
