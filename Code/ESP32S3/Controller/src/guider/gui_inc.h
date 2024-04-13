#ifndef _GUI_INC_H
#define _GUI_INC_H

#include "lvgl.h"

#define GUI_WIDTH TFT_HEIGHT
#define GUI_HEIGHT TFT_WIDTH

typedef enum
{
  LV_DISPLAY_HIDE,
  LV_DISPLAY_SHOW
} lv_display_t;

typedef enum
{
  STATE_OFF,
  STATE_ON
} lv_gui_state_t;


#endif