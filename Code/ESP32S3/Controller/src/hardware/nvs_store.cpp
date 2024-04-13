#include "nvs_store.h"

void NvsStore::init()
{
  // 强制初始化配置
#if NVS_ADMIN_INIT
  reset(NVS_NAMESPACE_BLOB_SYSTEM);
#endif

  // 初始化系统配置
  read(NVS_NAMESPACE_BLOB_SYSTEM);
  if (err != ESP_OK)
  {
    def_init(NVS_NAMESPACE_BLOB_SYSTEM);
  }
  SERIAL_ECHO_F("chipid: 0x%X%X%X%X\r\n",
                     nvs_sys_data.device_id[0],
                     nvs_sys_data.device_id[1],
                     nvs_sys_data.device_id[2],
                     nvs_sys_data.device_id[3]);
}

void NvsStore::def_init(const char *space)
{
  prefs.begin(space); // 打开命名空间
  SERIAL_ECHO_LN("nvs default init");
  if (strcmp(space, NVS_NAMESPACE_BLOB_SYSTEM) == 0)
  {
    uint32_t id = read_chip_id(); // 获取芯片ID

    nvs_sys_data.device_id[0] = (id >> 24) & 0xff;
    nvs_sys_data.device_id[1] = (id >> 16) & 0xff;
    nvs_sys_data.device_id[2] = (id >> 8) & 0xff;
    nvs_sys_data.device_id[3] = (id) & 0xff;

    memset(nvs_sys_data.wifi_ssid, 0x0, sizeof(nvs_sys_data.wifi_ssid));
    memset(nvs_sys_data.wifi_passwd, 0x0, sizeof(nvs_sys_data.wifi_passwd));

    nvs_sys_data.lcd_backlight = TFT_BL_DEFAULT;
    nvs_sys_data.lcd_touch_calibrate = 0;

    memset(nvs_sys_data.touch_caldata, 0x0, TOUCH_CALDATA_LEN * sizeof(uint16_t));
  }

  err = write(space);
  if (err == ESP_OK)
    SERIAL_ECHO_F("%s init sucess\r\n", space);
  else
    SERIAL_ECHO_F("%s init failed\r\n", space);

  prefs.end();
}

esp_err_t NvsStore::read(const char *space)
{
  prefs.begin(space);
  space_len = prefs.getBytesLength(space);
  err = ESP_OK;

  SERIAL_ECHO_F("nvs read %s, %d\r\n", space, space_len);
  if (strcmp(space, NVS_NAMESPACE_BLOB_SYSTEM) == 0)
  {
    prefs.getBytes(space, &nvs_sys_data, space_len);
    if (space_len == 0 || space_len % sizeof(nvs_blob_system_t))
      err = ESP_FAIL;
  }

  prefs.end();
  return err;
}

esp_err_t NvsStore::write(const char *space)
{
  prefs.begin(space);
  space_len = prefs.getBytesLength(space);
  err = ESP_OK;

  if (strcmp(space, NVS_NAMESPACE_BLOB_SYSTEM) == 0)
  {
    prefs.putBytes(space, &nvs_sys_data, sizeof(nvs_blob_system_t));
    if (space_len % sizeof(nvs_blob_system_t))
      err = ESP_FAIL;
  }

  prefs.end();
  return err;
}

void NvsStore::reset(const char *space)
{
  def_init(space);
}

uint32_t NvsStore::read_chip_id()
{
  uint32_t chipId = 0;
  for (int i = 0; i < 17; i = i + 8)
  {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  return chipId;
}