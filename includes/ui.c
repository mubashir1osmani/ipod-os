#include "lvgl/lvgl.h"

void UI_Init() {
    lv_init();                  // Initialize LVGL
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = my_flush_cb;  // Define your display flush function
    lv_disp_drv_register(&disp_drv);

    // Create a simple label
    lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "Quran Player");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
}