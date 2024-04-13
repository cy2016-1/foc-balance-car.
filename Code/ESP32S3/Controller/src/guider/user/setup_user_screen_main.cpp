#include "lvgl.h"
#include "gui_user.h"

static lv_anim_timeline_t *anim_timeline = NULL;
static uint8_t page_index;
static uint8_t anim_ready_count;

static const int interval_timer = 100;
static const int interval_wifi_update = (1000 / interval_timer);
static lv_timer_t *timer;
static int timer_count = 0;

static void timer_task(lv_timer_t *timer);

// 图标显示的位置和透明度数据
// x,y,opa
int icon_show_data[][3] = {
    {58, 40, LV_OPA_MAX},   // camera
    {198, 40, LV_OPA_MAX},  // data
    {58, 136, LV_OPA_MAX},  // setting
    {198, 136, LV_OPA_MAX}, // about
};
// 图标隐藏的位置和透明度数据
// x,y,opa
int icon_hide_data[][3] = {
    {-64, -64, LV_OPA_0},
    {320, -64, LV_OPA_0},
    {-64, 240, LV_OPA_0},
    {320, 240, LV_OPA_0},
};

static void anim_ready_callback(lv_anim_t *a)
{
  anim_ready_count++;
  int anim_count = (PAGE_MAX - 1) * 3;
  if (anim_ready_count >= anim_count)
  {
    if (anim_timeline)
    {
      lv_anim_timeline_del(anim_timeline);
      anim_timeline = NULL;
    }
    if (page_index != PAGE_MAX)
    {
      (page_index == PAGE_CAMERA || page_index == PAGE_SETTING) ? guiGotoPage((page_id_t)page_index) : guiGotoPageAnim((page_id_t)page_index);
    }
    else
    {
      lv_obj_clear_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN);
    }

    anim_ready_count = 0;
  }
}

static void scr_main_load_exit()
{
  lv_anim_t anim;
  lv_anim_init(&anim);

  lv_obj_t *icon_objs[] = {
      guider_ui.screen_main_imgbtn_camera,
      guider_ui.screen_main_imgbtn_pid,
      guider_ui.screen_main_imgbtn_setting,
      guider_ui.screen_main_imgbtn_about,
  };

  if (anim_timeline == NULL)
    anim_timeline = lv_anim_timeline_create();

  lv_obj_add_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN);

  if (page_index == PAGE_MAX)
  {
    // 页面加载
    for (int i = 0; i < PAGE_MAX - 1; i++)
    {
      // anim x
      ANIM_LINE_ADD(&anim, anim_x_cb, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_hide_data[i][0], icon_show_data[i][0], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
      // anim y
      ANIM_LINE_ADD(&anim, anim_y_cb, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_hide_data[i][1], icon_show_data[i][1], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
      // anim opa
      ANIM_LINE_ADD(&anim, set_img_opa, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_hide_data[i][2], icon_show_data[i][2], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
    }
  }
  else
  {
    // 页面退出
    for (int i = 0; i < PAGE_MAX - 1; i++)
    {
      // anim x
      ANIM_LINE_ADD(&anim, anim_x_cb, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_show_data[i][0], icon_hide_data[i][0], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
      // anim y
      ANIM_LINE_ADD(&anim, anim_y_cb, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_show_data[i][1], icon_hide_data[i][1], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
      // anim opa
      ANIM_LINE_ADD(&anim, set_img_opa, lv_anim_path_linear, anim_ready_callback, 250, 0, 0, icon_objs[i], icon_show_data[i][2], icon_hide_data[i][2], 0);
      lv_anim_timeline_add(anim_timeline, 0, &anim);
    }
  }

  lv_anim_timeline_start(anim_timeline);
}

static void timer_task(lv_timer_t *timer)
{
  if (timer_count % interval_wifi_update == 0)
  {
    // 更新wifi图标状态
    if (wifi_dev.wifi_is_conn())
    {
      if (lv_img_get_src(guider_ui.screen_main_img_wifi) != &_wifi_conn_alpha_32x32)
      {
        lv_img_set_src(guider_ui.screen_main_img_wifi, &_wifi_conn_alpha_32x32);
      }
    }
    else
    {
      if (lv_img_get_src(guider_ui.screen_main_img_wifi) != &_wifi_disconn_alpha_32x32)
      {
        lv_img_set_src(guider_ui.screen_main_img_wifi, &_wifi_disconn_alpha_32x32);
      }
    }
  }

  if (++timer_count > INT32_MAX)
    timer_count = 0;
}

static void click_event_handler(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  if (obj == guider_ui.screen_main_imgbtn_camera)
  {
    page_index = PAGE_CAMERA;
  }
  else if (obj == guider_ui.screen_main_imgbtn_pid)
  {
    page_index = PAGE_DATA;
  }
  else if (obj == guider_ui.screen_main_imgbtn_setting)
  {
    page_index = PAGE_SETTING;
  }
  else if (obj == guider_ui.screen_main_imgbtn_about)
  {
    page_index = PAGE_ABOUT;
  }

  if (page_index != PAGE_MAX)
  {
    lv_timer_del(timer);
    scr_main_load_exit();
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

void setup_user_screen_main(lv_ui *ui)
{
  page_index = PAGE_MAX;
  anim_ready_count = 0;
  timer_count = 0;
  timer = lv_timer_create(timer_task, interval_timer, NULL);

  lv_obj_clear_flag(ui->screen_main, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_add_event_cb(ui->screen_main_imgbtn_camera, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_main_imgbtn_pid, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_main_imgbtn_setting, screen_event_handler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui->screen_main_imgbtn_about, screen_event_handler, LV_EVENT_CLICKED, NULL);

  scr_main_load_exit();
}