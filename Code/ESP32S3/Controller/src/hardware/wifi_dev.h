#pragma once

typedef void (*scan_callback)(int num);
typedef void (*status_callback)();

class Wifi_Dev
{
private:
  int wifi_num;
  char wifi_ssid[32][32];
  bool wifi_scan_flag;
  bool wifi_connect_flag;

  scan_callback scan_cb;
  status_callback status_cb;

  char info_ssid[32];
  char info_passwd[32];

  char info_ip[32];

public:
  Wifi_Dev();
  ~Wifi_Dev();
  void wifi_scan();
  void wifi_scan_stop();
  void wifi_scan_set_cb(scan_callback cb);

  void wifi_connect();
  void wifi_disconnect();
  void wifi_status_set_cb(status_callback cb);

  void wifi_status_detect();

  void wifi_set_info(const char *ssid, const char *passwd);

  const char *wifi_get_ssid(int index) { return wifi_ssid[index]; }
  const char *wifi_get_conn_ssid() { return info_ssid; }
  const char *wifi_get_conn_passwd() { return info_passwd; }
  const char *wifi_get_ip() { return info_ip; }
  bool wifi_is_scan() { return wifi_scan_flag; }
  bool wifi_is_conn() { return wifi_connect_flag; }
};
