#pragma once

#include <Arduino.h>
#include <vector>
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_helper.h"
#include "gui_user.h"

using namespace std;

class GuiPort
{
private:
  void pageInit();
  void pageAdd(page_desc_t &page);
  void pageRemove(page_desc_t &page);

  vector<page_desc_t> pages_list;
  SemaphoreHandle_t lvgl_mutex = xSemaphoreCreateMutex();

public:
  GuiPort();
  ~GuiPort();

  void guiHandleTask()
  {
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_task_handler();
    xSemaphoreGive(lvgl_mutex);
  }
  void guiTickTask(uint32_t t)
  {
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_tick_inc(t);
    xSemaphoreGive(lvgl_mutex);
  }

  void guiReadMem(uint8_t *pmem)
  {
    lv_mem_monitor_t gui_mem_monitor;
    lv_mem_monitor(&gui_mem_monitor);

    if (!pmem)
    {
      SERIAL_ECHO_F("lv_mem: %d%%\n", gui_mem_monitor.used_pct);
    }
    else
      *pmem = gui_mem_monitor.used_pct;
  }

  void guiInit();

  void gotoPage(page_id_t id, bool en_anim = true);
  page_desc_t *getPageDesc(page_id_t id);
};

extern GuiPort myGUI;
