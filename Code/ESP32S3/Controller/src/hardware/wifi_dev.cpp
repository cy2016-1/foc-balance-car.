#include "wifi_dev.h"
#include <WiFi.h>
#include "user_config.h"

void WiFiEvent(WiFiEvent_t event)
{
  switch (event)
  {
  case ARDUINO_EVENT_WIFI_STA_CONNECTED:
    Serial.println("wifi sta connected");
    break;
  case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
    Serial.println("wifi sta disconnected");
    break;
  case ARDUINO_EVENT_WIFI_STA_GOT_IP:
    Serial.println("wifi sta got ip");
    break;
  default:
    break;
  }
}

Wifi_Dev::Wifi_Dev()
{
  // WiFi.onEvent(WiFiEvent);
  // WiFi.setAutoConnect(false);
  WiFi.setTxPower(WIFI_POWER_19_5dBm);
  WiFi.setAutoReconnect(false);
}

Wifi_Dev::~Wifi_Dev()
{
}

void Wifi_Dev::wifi_scan()
{
  if (wifi_scan_flag)
    return;

  wifi_num = 0;
  memset(wifi_ssid, 0x0, sizeof(wifi_ssid));
  wifi_scan_flag = true;

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);

  delay(100);

  wifi_num = WiFi.scanNetworks();
  wifi_num = (wifi_num < 32) ? wifi_num : 32;

  if (wifi_num > 0)
  {
    for (int i = 0; i < wifi_num; i++)
    {
      String ssid = WiFi.SSID(i);
      memcpy(wifi_ssid[i], ssid.c_str(), ssid.length());
    }
  }

  WiFi.scanDelete();
  wifi_scan_flag = false;

  if (NULL != scan_cb)
  {
    scan_cb(wifi_num);
  }
}

void Wifi_Dev::wifi_scan_stop()
{
  WiFi.scanDelete();
}

void Wifi_Dev::wifi_scan_set_cb(scan_callback cb)
{
  scan_cb = cb;
}

void Wifi_Dev::wifi_connect()
{
  if (NULL == info_ssid || NULL == info_passwd)
  {
    return;
  }

  wifi_connect_flag = false;
  WiFi.disconnect(true);
  delay(100);

  SERIAL_ECHO_F("%s - %s\n", info_ssid, info_passwd);
  WiFi.begin(info_ssid, info_passwd);
}

void Wifi_Dev::wifi_disconnect()
{
  WiFi.disconnect();
}

void Wifi_Dev::wifi_status_set_cb(status_callback cb)
{
  status_cb = cb;
}

void Wifi_Dev::wifi_set_info(const char *ssid, const char *passwd)
{
  memset(info_ssid, 0x0, sizeof(info_ssid));
  memset(info_passwd, 0x0, sizeof(info_passwd));

  memcpy(info_ssid, ssid, strlen(ssid));
  memcpy(info_passwd, passwd, strlen(passwd));
};

void Wifi_Dev::wifi_status_detect()
{
  if(wifi_scan_flag)
    return;

  switch (WiFi.status())
  {
  case WL_CONNECT_FAILED:
    SERIAL_ECHO_LN("wifi connect failed");
    if(NULL != status_cb) status_cb();
    break;
  case WL_CONNECTION_LOST:
  case WL_DISCONNECTED:
    if (wifi_connect_flag)
    {
      SERIAL_ECHO_LN("wifi disconnected");
      wifi_connect_flag = false;
      memset(info_ip, 0x0, sizeof(info_ip));
      if(NULL != status_cb) status_cb();
    }
    break;
  case WL_CONNECTED:
    if (!wifi_connect_flag)
    {
      SERIAL_ECHO_LN("wifi connected");
      wifi_connect_flag = true;
      String ip = WiFi.localIP().toString();
      memset(info_ip, 0x0, sizeof(info_ip));
      memcpy(info_ip, ip.c_str(), ip.length());
      if(NULL != status_cb) status_cb();
    }
    break;
  default:
    break;
  }
}
