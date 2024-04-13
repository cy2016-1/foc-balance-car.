#include "gui_port.h"

GuiPort myGUI;
lv_ui guider_ui;

#define PAGE_START PAGE_MAIN

page_desc_t def_page_array[] = {
    {PAGE_MAIN, "main", &guider_ui.screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, setup_scr_screen_main, setup_user_screen_main},
    {PAGE_CAMERA, "camera", &guider_ui.screen_camera, LV_SCR_LOAD_ANIM_MOVE_TOP, setup_scr_screen_camera, setup_user_screen_camera},
    {PAGE_DATA, "data", &guider_ui.screen_data, LV_SCR_LOAD_ANIM_MOVE_TOP, setup_scr_screen_data, setup_user_screen_data},
    {PAGE_SETTING, "setting", &guider_ui.screen_setting, LV_SCR_LOAD_ANIM_MOVE_TOP, setup_scr_screen_setting, setup_user_screen_setting},
    {PAGE_ABOUT, "about", &guider_ui.screen_about, LV_SCR_LOAD_ANIM_MOVE_TOP, setup_scr_screen_about, setup_user_screen_about},
};

GuiPort::GuiPort()
{
}

GuiPort::~GuiPort()
{
}

void GuiPort::guiInit()
{
  lv_init();            // lvgl 系统初始化
  lv_port_disp_init();  // lvgl 显示接口初始化
  lv_port_indev_init(); // lvgl 输入接口初始化

  // lv_group_set_default(my_group); // 设置默认分组

  pageInit(); // 页面管理初始化
}

void GuiPort::gotoPage(page_id_t id, bool en_anim)
{
  page_desc_t *pagePtr = getPageDesc(id);
  if (pagePtr == nullptr)
    return;

  lv_obj_t *act_scr = lv_scr_act();
  lv_disp_t *d = lv_obj_get_disp(act_scr);

  lv_obj_set_style_bg_opa(act_scr, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(act_scr, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);

  if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
  {
    pagePtr->setup_handle(&guider_ui);
    pagePtr->setup_user_handle(&guider_ui); // 用户自定义初始化

    if (en_anim)
      lv_scr_load_anim(*(pagePtr->obj), pagePtr->load_anim, 100, 0, true);
    else
      lv_scr_load_anim(*(pagePtr->obj), LV_SCR_LOAD_ANIM_NONE, 100, 0, true);
  }
}

page_desc_t *GuiPort::getPageDesc(page_id_t id)
{
  vector<page_desc_t>::iterator iter;
  for (iter = pages_list.begin(); iter != pages_list.end(); iter++)
  {
    if ((iter->id) == id)
      return &(*iter);
  }

  return nullptr;
}

/***********************************************
 * PRIVATE
 ***********************************************/
void GuiPort::pageInit()
{
  size_t len = COUNT_OF(def_page_array);
  for (int i = 0; i < len; i++)
  {
    pageAdd(def_page_array[i]);
  }

  gotoPage(PAGE_START, false);
}

void GuiPort::pageAdd(page_desc_t &page)
{
  bool page_exist = false;
  vector<page_desc_t>::iterator iter;
  for (iter = pages_list.begin(); iter != pages_list.end(); iter++)
  {
    if (iter->id == page.id || strcmp(iter->name, page.name) == 0)
    {
      SERIAL_ECHO_LN("page exist!");
      page_exist = true;
      break;
    }
  }

  if (!page_exist)
  {
    pages_list.push_back(page);
    SERIAL_ECHO_F("page add -> %s\n", page.name);
  }
}

void GuiPort::pageRemove(page_desc_t &page)
{
  vector<page_desc_t>::iterator iter;
  for (iter = pages_list.begin(); iter != pages_list.end(); iter++)
  {
    if (iter->id == page.id && strcmp(iter->name, page.name) == 0)
    {
      SERIAL_ECHO_F("page del -> %s\n", iter->name);
      pages_list.erase(iter);
      break;
    }
  }
}
