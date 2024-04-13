#ifndef _GUI_USER_H
#define _GUI_USER_H

#include "lvgl.h"
#include "gui_inc.h"
#include "gui_guider.h"
#include "gui_helper.h"
#include "user_config.h"
#include "build_def.h"
#include "extern_inc.h"

#include "lv_com_keyboard.h"

#define LV_OPA_SHOW LV_OPA_100
#define LV_OPA_HIDE LV_OPA_50

#define OBJ_OPA_SHOW(obj, part, type) lv_obj_set_style_##type##_opa(obj, LV_OPA_SHOW, LV_PART_##part)
#define OBJ_OPA_HIDE(obj, part, type) lv_obj_set_style_##type##_opa(obj, LV_OPA_HIDE, LV_PART_##part)

#define ANIM_LINE_ADD(a, exec_cb, path_cb, ready_cb, time, back_time, delay, var, begin, end, repeatcnt) \
  do                                                                                                     \
  {                                                                                                      \
    lv_anim_init(a);                                                                                     \
    lv_anim_set_exec_cb(a, exec_cb);                                                                     \
    if (path_cb != NULL)                                                                                 \
      lv_anim_set_path_cb(a, path_cb);                                                                   \
    if (ready_cb != NULL)                                                                                \
      lv_anim_set_ready_cb(a, ready_cb);                                                                 \
    lv_anim_set_time(a, time);                                                                           \
    lv_anim_set_playback_time(a, back_time);                                                             \
    lv_anim_set_delay(a, delay);                                                                         \
    lv_anim_set_var(a, var);                                                                             \
    lv_anim_set_values(a, begin, end);                                                                   \
    lv_anim_set_repeat_count(a, repeatcnt);                                                              \
  } while (0);

typedef struct{
    lv_obj_t* parent;
    kb_ready_handle_t ready_handle;
    const char* title_txt;
    const char* content_txt;
    bool one_line;
}keyboard_helper_t;

static inline void set_angle(void *obj, int32_t v)
{
  lv_arc_set_value((lv_obj_t *)obj, (int32_t)v);
}

static inline void set_img_angle(void *img, int32_t v)
{
  lv_img_set_angle((lv_obj_t *)img, v);
}

static inline void set_img_opa(void *var, int32_t v)
{
  lv_obj_t *obj = (lv_obj_t *)var;
  lv_obj_set_style_img_opa((lv_obj_t *)var, v, (int)obj->user_data);
}

static inline void anim_opa_cb(void *var, int32_t v)
{
  lv_obj_t *obj = (lv_obj_t *)var;
  lv_obj_set_style_opa((lv_obj_t *)var, v, (int)obj->user_data);
}

static inline void anim_y_cb(void *var, int32_t v)
{
  lv_obj_set_y((lv_obj_t *)var, v);
}

static inline void anim_x_cb(void *var, int32_t v)
{
  lv_obj_set_x((lv_obj_t *)var, v);
}

static lv_obj_t *keyboard_create(keyboard_helper_t* kb_helper)
{
  lv_obj_t* keyboard = lv_com_keyboard_create(kb_helper->parent);
  lv_obj_align(keyboard, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_com_keyboard_set_readycb(keyboard, kb_helper->ready_handle);

  lv_com_keyboard_one_line(keyboard, (lv_gui_state_t)kb_helper->one_line);
  lv_com_keyboard_display(keyboard,
                          kb_helper->title_txt,
                          kb_helper->content_txt,
                          LV_DISPLAY_SHOW);

  return keyboard;
}

static int is_jpg(const uint8_t *raw_data)
{
  const uint8_t jpg_signature[] = {0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46};
  return memcmp(jpg_signature, raw_data, sizeof(jpg_signature)) == 0;
}

LV_IMG_DECLARE(_wifi_conn_alpha_32x32);

void setup_user_screen_main(lv_ui *ui);
void setup_user_screen_camera(lv_ui *ui);
void setup_user_screen_data(lv_ui *ui);
void setup_user_screen_setting(lv_ui *ui);
void setup_user_screen_about(lv_ui *ui);

#endif