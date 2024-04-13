#ifndef _USER_CONFIG_H
#define _USER_CONFIG_H

/*********************************************************
引脚说明：
TFT LCD屏幕
  VCC
  GND
  CS   - 42
  RST  - -1
  DC   - 41
  MOSI - 40
  SCK  - 39
  LED  - 45
  MISO - -1
  TCLK - SCK
  TCS  - 48
  TDIN - MOSI
  TDO  - 47 (T-MISO)
  TIRQ - -1

摇杆模块
  VCC  - 5V
  GND
  X    - 12
  Y    - 13
  B    - 14

*********************************************************/
#include <Arduino.h>

// Version
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

#define _VerJoin(a, b, c) STRINGIFY(a.b.c)
#define FIRMWARE_VER _VerJoin(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)
#define FIRMWARE_VER_STR "firmware version " FIRMWARE_VER ", compiled on " __DATE__ " at " __TIME__

#define DEBUG_ENABLE 1
#define NVS_ADMIN_INIT 0

#define WIFI_STA_SSID "ESP32CAM"
#define WIFI_STA_PWD "12345678"

#define CAMERA_SERVER_HOST "http://192.168.4.1"        // 服务器地址
#define CAMERA_CONTROL_API "%s/control?var=%s&val=%d"  // 参数设置API
#define CAMERA_STREAM_API "%s:81/stream"               // 视频流API
#define CAMERA_ROCKER_API "%s/rocker?x=%d&y=%d&sw=%d"  // 移动控制API(未使用)
#define CAMERA_COMMAND_API "%s/command?type=%d&cmd=%s" // 命令设置API

#define COMMAND_UPLOAD_PID "M0_UP"           // PID数据
#define COMMAND_UPLOAD_GYROSCOPEDATA "M0_UG" // 陀螺仪数据
#define COMMAND_UPLOAD_VELOCITY "M0_UV"      // 速度
#define COMMAND_UPLOAD_TURN "M0_UT"          // 转向

#define COMMAND_STORE_PID "M0_SP" // 保存PID
#define COMMAND_RESET_PID "M0_RP" // 重置PID

#define COMMAND_SET_VELOCITY "M0_V%.3f" // 设置速度
#define COMMAND_SET_TURN "M0_T%.3f"     // 设置转向
#define COMMAND_SET_PID "M0_%s%.3f"     // 设置PID

#define TFT_BL_DEFAULT 5

#if DEBUG_ENABLE
#define SERIAL_ECHO(x) Serial.print(F(x));
#define SERIAL_ECHO_LN(x) Serial.println(F(x));
#define SERIAL_ECHO_F(__info, ...) Serial.printf(__info, ##__VA_ARGS__)
#else
#define SERIAL_ECHO(x)
#define SERIAL_ECHO_LN(x)
#define SERIAL_ECHO_F(__info, ...)
#endif

#endif