#include "lv_com_keyboard.h"

#define COM_KEYBOARD_WIDTH GUI_WIDTH
#define COM_KEYBOARD_HEIGHT GUI_HEIGHT

#define MY_CLASS &com_keyboard_class

static void com_keyboard_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void com_keyboard_destructor(const lv_obj_class_t *class_p, lv_obj_t *obj);

static void anim_ready_cb(lv_anim_t *a);
static inline void anim_h_cb(void *var, int32_t v);

const lv_obj_class_t com_keyboard_class = {
    .constructor_cb = com_keyboard_constructor,
    .destructor_cb = com_keyboard_destructor,
    .width_def = COM_KEYBOARD_WIDTH,
    .height_def = COM_KEYBOARD_HEIGHT,
    .instance_size = sizeof(lv_com_keyboard_t),
    .base_class = &lv_obj_class};

/*keyboard map*/
const char *kb_map[] = {
    "1$", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
    LV_SYMBOL_UP, "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_NEW_LINE, "\n",
    " ", "-", "z", "x", "c", "v", "b", "n", "m", ".", " ", "\n",
    " ", LV_SYMBOL_CLOSE, " ", LV_SYMBOL_OK, " ", NULL};
const char *kb_map_up[] = {
    "1$", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
    LV_SYMBOL_DOWN, "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_NEW_LINE, "\n",
    " ", "-", "Z", "X", "C", "V", "B", "N", "M", ".", " ", "\n",
    " ", LV_SYMBOL_CLOSE, " ", LV_SYMBOL_OK, " ", NULL};
const char *kb_map_num[] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    LV_SYMBOL_BACKSPACE,
    "\n",
    LV_SYMBOL_UP,
    "+",
    "-",
    "*",
    "/",
    "=",
    "%",
    "!",
    "?",
    "#",
    "<",
    ">",
    "\n",
    " ",
    "\\",
    "_",
    ",",
    "(",
    ")",
    "{",
    "}",
    "[",
    "]",
    "^",
    "&",
    ";",
    ":",
    "\"",
    "'",
    " ",
    "\n",
    " ",
    LV_SYMBOL_CLOSE,
    "@",
    " ",
    "$",
    LV_SYMBOL_OK,
    " ",
    NULL,
};

/*keyboard map controls*/
const lv_btnmatrix_ctrl_t kb_ctrl[] = {
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    6,
    6,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    6,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
    4,
    6,
    4,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
};
const lv_btnmatrix_ctrl_t kb_ctrl_num[] = {
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    6,
    6,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    LV_BTNMATRIX_CTRL_HIDDEN | 2,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    LV_BTNMATRIX_CTRL_HIDDEN | 2,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
    4,
    4,
    6,
    4,
    4,
    LV_BTNMATRIX_CTRL_HIDDEN | 4,
};

lv_obj_t *lv_com_keyboard_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

void lv_com_keyboard_display(lv_obj_t *obj, const char *title, const char *content, lv_display_t state)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)obj;

    lv_anim_t a;
    lv_anim_init(&a);

    if (state == LV_DISPLAY_HIDE)
    {
        lv_anim_set_var(&a, obj);
        lv_anim_set_values(&a, GUI_HEIGHT, 0);
        lv_anim_set_time(&a, 100);
        lv_anim_set_delay(&a, 10);
        lv_anim_set_path_cb(&a, lv_anim_path_linear);
        lv_anim_set_exec_cb(&a, anim_h_cb);
        lv_anim_set_ready_cb(&a, anim_ready_cb);

        lv_obj_t *parent = lv_obj_get_parent(obj);
        lv_group_focus_obj(parent);
    }
    else if (state == LV_DISPLAY_SHOW)
    {
        lv_anim_set_var(&a, obj);
        lv_anim_set_values(&a, 0, GUI_HEIGHT);
        lv_anim_set_time(&a, 100);
        lv_anim_set_delay(&a, 10);
        lv_anim_set_path_cb(&a, lv_anim_path_linear);
        lv_anim_set_exec_cb(&a, anim_h_cb);

        //设置标题
        if (title != NULL)
            lv_label_set_text(com_keyboard->label_info, title);
        if (content != NULL)
            lv_textarea_set_text(com_keyboard->ta_input, content);
        lv_group_focus_obj(com_keyboard->kb);
    }

    lv_anim_start(&a);
}

/**********************
 *   SET FUNCTIONS
 **********************/
static void anim_ready_cb(lv_anim_t *a)
{
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)(a->var);
    lv_textarea_set_one_line(com_keyboard->ta_input, false); //关闭单行模式

    lv_obj_del_async(a->var);
}

void lv_com_keyboard_set_readycb(lv_obj_t *obj, kb_ready_handle_t handler)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)obj;

    com_keyboard->kb_ready_handler = handler;
}

void lv_com_keyboard_one_line(lv_obj_t *obj, lv_gui_state_t state)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)obj;

    lv_textarea_set_one_line(com_keyboard->ta_input, state);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void keyboard_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *parent = lv_obj_get_parent(obj);

    LV_ASSERT_OBJ(parent, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)parent;

    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_READY)
    {
        if (com_keyboard->kb_ready_handler == NULL)
            return;
        com_keyboard->kb_ready_handler(parent, lv_textarea_get_text(com_keyboard->ta_input));
        lv_com_keyboard_display(com_keyboard, NULL, NULL, LV_DISPLAY_HIDE);
    }
    else if (code == LV_EVENT_CANCEL)
    {
        lv_com_keyboard_display(com_keyboard, NULL, NULL, LV_DISPLAY_HIDE);
    }
}

static void keyboard_event_valchanged_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *parent = lv_obj_get_parent(obj);

    LV_ASSERT_OBJ(parent, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)parent;

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_keyboard_t *keyboard = (lv_keyboard_t *)obj;
    uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj);
    if (btn_id == LV_BTNMATRIX_BTN_NONE)
        return;

    const char *txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if (txt == NULL)
        return;

    if (strcmp(txt, LV_SYMBOL_UP) == 0)
    {
        //大写模式
        lv_keyboard_set_map(com_keyboard->kb, LV_KEYBOARD_MODE_USER_1, kb_map_up, kb_ctrl);
        lv_textarea_del_char(com_keyboard->ta_input);
        return;
    }
    else if (strcmp(txt, LV_SYMBOL_DOWN) == 0)
    {
        //小写模式
        lv_keyboard_set_map(com_keyboard->kb, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
        lv_textarea_del_char(com_keyboard->ta_input);
        return;
    }
    else if (strcmp(txt, "1$") == 0)
    {
        //数字模式
        lv_keyboard_set_map(com_keyboard->kb, LV_KEYBOARD_MODE_USER_1, kb_map_num, kb_ctrl_num);
        lv_textarea_del_char(com_keyboard->ta_input); //删除两个字符("1$")
        lv_textarea_del_char(com_keyboard->ta_input);
        return;
    }
}

static void com_keyboard_init(lv_obj_t *obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_com_keyboard_t *com_keyboard = (lv_com_keyboard_t *)obj;
    lv_obj_set_style_bg_opa(obj, LV_OPA_MAX, LV_PART_MAIN);
    lv_obj_center(obj);

    /*Create a keyboard and add the new map as USER_1 mode*/
    com_keyboard->kb = lv_keyboard_create(obj);
    lv_obj_set_style_bg_color(com_keyboard->kb, lv_palette_main(LV_PALETTE_PINK), LV_PART_ITEMS);
    lv_obj_add_event_cb(com_keyboard->kb, keyboard_event_cb, LV_EVENT_READY, NULL);
    lv_obj_add_event_cb(com_keyboard->kb, keyboard_event_cb, LV_EVENT_CANCEL, NULL);
    lv_obj_add_event_cb(com_keyboard->kb, keyboard_event_valchanged_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_group_add_obj(lv_group_get_default(), com_keyboard->kb);

    lv_keyboard_set_map(com_keyboard->kb, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
    lv_keyboard_set_mode(com_keyboard->kb, LV_KEYBOARD_MODE_USER_1);

    //文字提示标签
    com_keyboard->label_info = lv_label_create(obj);
    lv_obj_set_size(com_keyboard->label_info, LV_PCT(80), LV_SIZE_CONTENT);
    // lv_obj_set_style_text_font(com_keyboard->label_info, &font_sung_14, LV_PART_MAIN);
    lv_obj_set_style_text_align(com_keyboard->label_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_label_set_long_mode(com_keyboard->label_info, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(com_keyboard->label_info, "");
    lv_obj_align_to(com_keyboard->label_info, com_keyboard->kb, LV_ALIGN_OUT_TOP_MID, 0, -10);

    //输入文本框
    com_keyboard->ta_input = lv_textarea_create(obj);
    lv_obj_set_style_border_color(com_keyboard->ta_input, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_size(com_keyboard->ta_input, LV_PCT(85), 40);
    lv_obj_align_to(com_keyboard->ta_input, com_keyboard->label_info, LV_ALIGN_OUT_TOP_MID, 0, -20);

    //隐藏
    lv_obj_set_height(obj, 0);
    lv_keyboard_set_textarea(com_keyboard->kb, com_keyboard->ta_input);
}

static void com_keyboard_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    com_keyboard_init(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void com_keyboard_destructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
}

static inline void anim_h_cb(void *var, int32_t v)
{
    lv_obj_set_height(var, v);
}
