#include "lvgl.h"
#include "gui_user.h"

static void click_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  if (obj == guider_ui.screen_about_btn_back)
  {
    guiGotoPageAnim(PAGE_MAIN);
  }
}

static void screen_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  switch (code)
  {
  case LV_EVENT_CLICKED:
  {
    click_event_handler(e);
    break;
  }
  default:
    break;
  }
}

void setup_user_screen_about(lv_ui *ui)
{
  lv_obj_add_event_cb(ui->screen_about_btn_back, screen_event_handler, LV_EVENT_CLICKED, NULL);

  lv_label_set_text_fmt(ui->screen_about_label_version, "V%s", FIRMWARE_VER);
  lv_label_set_text_fmt(ui->screen_about_label_date, "%04d-%02d-%02d\n%02d:%02d:%02d",
                        BUILD_YEAR, BUILD_MONTH, BUILD_DAY,
                        BUILD_HOUR, BUILD_MIN, BUILD_SEC);
}