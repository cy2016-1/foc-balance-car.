#include "touch_cal.h"
#include "extern_inc.h"

void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // 检测系统配置屏幕是否已校准
  if (nvs.nvs_sys_data.lcd_touch_calibrate)
  {
    SERIAL_ECHO_LN("Touch calibration parameters detected!");
    return;
  }

  // 清空校准参数缓存区
  memset(nvs.nvs_sys_data.touch_caldata, 0x0, TOUCH_CALDATA_LEN * sizeof(uint16_t));

  // Calibrate
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.println("Touch corners as indicated");

  tft.setTextFont(1);
  tft.println();

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  SERIAL_ECHO_LN("// Use this calibration code in setup():");
  SERIAL_ECHO("  uint16_t calData[5] = ");
  SERIAL_ECHO("{ ");

  // 存储校准参数
  for (uint8_t i = 0; i < 5; i++)
  {
    nvs.nvs_sys_data.touch_caldata[i] = calData[i];
    SERIAL_ECHO_F("%d", calData[i]);
    if (i < 4)
      SERIAL_ECHO(", ");
  }

  SERIAL_ECHO(" };");
  SERIAL_ECHO_LN("  tft.setTouch(calData);");

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");
  tft.println("Calibration code saving...");

  nvs.nvs_sys_data.lcd_touch_calibrate = 1;
  nvs.write(NVS_NAMESPACE_BLOB_SYSTEM);

  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration code saved!");
  delay(4000);
}
