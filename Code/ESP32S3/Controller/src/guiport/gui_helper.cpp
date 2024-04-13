#include "gui_helper.h"
#include "gui_port.h"

void guiGotoPageAnim(page_id_t id)
{
  myGUI.gotoPage(id);
}

void guiGotoPage(page_id_t id)
{
  myGUI.gotoPage(id, false);
}

page_desc_t *guiGetPageDesc(page_id_t id)
{
  return myGUI.getPageDesc(id);
}

lv_obj_t * toastMsgBox(lv_obj_t *parent, const char *title, const char *txt)
{
  static const char *msgbox_btns[] = {""};
  if (parent == NULL)
    return NULL;

  lv_obj_t *msgbox = lv_msgbox_create(parent, title, txt, msgbox_btns, true);
  lv_obj_set_size(lv_msgbox_get_btns(msgbox), 60, 30);
  lv_obj_set_pos(msgbox, 38, 45);
  lv_obj_set_size(msgbox, 246, 136);
  lv_obj_set_scrollbar_mode(msgbox, LV_SCROLLBAR_MODE_OFF);

  return msgbox;
}