#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "user_config.h"
#include <TFT_eSPI.h>
#include "gui_port.h"
#include "touch_cal.h"
#include "nvs_store.h"
#include "wifi_dev.h"
#include "rocker.h"
#include "extern_inc.h"

TFT_eSPI tft = TFT_eSPI();
Rocker rocker(ROCKER_PIN_X, ROCKER_PIN_Y, ROCKER_PIN_B);
NvsStore nvs;
Wifi_Dev wifi_dev;
HttpRequest http_client;

QueueHandle_t queue_handle;

uint32_t loop_millis;

void guiHandleTaskFunc(void *param);
void guiTickTaskFunc(void *param);
void queueTaskFunc(void *param);
void wifiTaskFunc(void *param);
void httpTaskFunc(void *param);
void streamTaskFunc(void *param);

void system_info_log()
{
  SERIAL_ECHO_F("Deafult free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
  SERIAL_ECHO_F("Flash size: %d bytes\n", ESP.getFlashChipSize());
  if (psramFound())
  {
    SERIAL_ECHO_F("PSRAM free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
  }
  else
  {
    SERIAL_ECHO_LN("PSRAM Not Found");
  }
}

void setup()
{
  Serial.begin(115200);
  SERIAL_ECHO_LN("FOCBalanceCar Controller");
  SERIAL_ECHO_F("%s\n", FIRMWARE_VER_STR);

  system_info_log();

  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, LOW);
  analogWriteFrequency(10000);

  // NVS初始化
  nvs.init();

  // LCD初始化
  tft.initDMA(true);
  tft.begin();
  tft.setRotation(TFT_ROTATION);
  tft.setSwapBytes(TFT_SWAPBYTES);
  tft.fillScreen(TFT_BLACK);

  tft_led_set(nvs.nvs_sys_data.lcd_backlight);

  // 屏幕触摸校准
  touch_calibrate();
  tft.setTouch(nvs.nvs_sys_data.touch_caldata);

  //摇杆范围设置
  rocker.set_mid_val(ROCKER_MID_VAL_X, ROCKER_MID_VAL_Y, ROCKER_VAL_OFFSET);
  rocker.set_velocity_range(-15, 15);
  rocker.set_steering_range(-10, 10);

  // GUI初始化
  myGUI.guiInit();

  // 创建GUI任务
  xTaskCreatePinnedToCore(guiHandleTaskFunc, "guiHandleTask", 4096, NULL, 3, NULL, 0);
  xTaskCreatePinnedToCore(guiTickTaskFunc, "guiTickTask", 4096, NULL, 3, NULL, 0);

  // 创建外设任务
  queue_handle = xQueueCreate(32, sizeof(task_queue_type_t));
  xTaskCreatePinnedToCore(queueTaskFunc, "queueTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(wifiTaskFunc, "wifiTask", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(httpTaskFunc, "httpTask", 4096, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(streamTaskFunc, "streamTask", 4096, NULL, 1, NULL, 0);

  loop_millis = millis();
}

void loop()
{
  if(millis() - loop_millis > 100)
  {
    loop_millis = millis();
    rocker.read();
  }
}

void taskQueueAdd(task_queue_type_t queue_type)
{
  xQueueSendToBack(queue_handle, &queue_type, 0);
}

void guiHandleTaskFunc(void *param)
{
  for (;;)
  {
    myGUI.guiHandleTask();
    vTaskDelay(10);
  }

  vTaskDelete(NULL);
}

void guiTickTaskFunc(void *param)
{
  for (;;)
  {
    myGUI.guiTickTask(5);
    vTaskDelay(5);
  }

  vTaskDelete(NULL);
}

void httpTaskFunc(void *param)
{
  for (;;)
  {
    if (wifi_dev.wifi_is_conn())
      http_client.request();
    else
      delay(500);
  }

  vTaskDelete(NULL);
}

void streamTaskFunc(void *param)
{
  http_client.stream_handler();
  vTaskDelete(NULL);
}

void queueTaskFunc(void *param)
{
  task_queue_type_t task_queu_type;
  BaseType_t xStatus;

  for (;;)
  {
    xStatus = xQueueReceive(queue_handle, &task_queu_type, portMAX_DELAY);
    if (xStatus == pdPASS)
    {
      if (task_queu_type == TASK_QUEUE_TYPE_WIFI_SCAN)
      {
        wifi_dev.wifi_scan();
      }
      else if (task_queu_type == TASK_QUEUE_TYPE_WIFI_CONNECT)
      {
        wifi_dev.wifi_connect();
      }
    }
  }

  vTaskDelete(NULL);
}

void wifiTaskFunc(void *param)
{
  for (;;)
  {
    wifi_dev.wifi_status_detect();
    delay(1000);
  }
  vTaskDelete(NULL);
}