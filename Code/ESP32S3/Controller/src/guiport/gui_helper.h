#ifndef _GUI_HELPER_H
#define _GUI_HELPER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include "gui_guider.h"
#include "macro.h"

  typedef struct
  {
    uint8_t id;
    const char *name;
    lv_obj_t **obj;
    lv_scr_load_anim_t load_anim;

    void (*setup_handle)(lv_ui *ui);
    void (*setup_user_handle)(lv_ui *ui);
  } page_desc_t;

  typedef enum
  {
    PAGE_MAIN = 0, // 主页面
    PAGE_CAMERA,   // 摄像头页面
    PAGE_DATA,     // 数据页面
    PAGE_SETTING,  // 设置页面
    PAGE_ABOUT,    // 关于页面
    PAGE_MAX,      // 页面最大值
  } page_id_t;

  void guiGotoPage(page_id_t id);
  void guiGotoPageAnim(page_id_t id);
  void taskPause(uint8_t id);
  void taskResume(uint8_t id);
  page_desc_t *guiGetPageDesc(page_id_t id);
  lv_obj_t *toastMsgBox(lv_obj_t *box, const char *title, const char *txt);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif