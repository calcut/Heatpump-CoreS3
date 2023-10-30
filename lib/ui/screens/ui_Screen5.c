// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: CoreS3_SLS_Project

#include "../ui.h"

void ui_Screen5_screen_init(void)
{
ui_Screen5 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Header5 = lv_obj_create(ui_Screen5);
lv_obj_set_height( ui_Header5, 25);
lv_obj_set_width( ui_Header5, lv_pct(100));
lv_obj_set_align( ui_Header5, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_Header5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Header5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Header5, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Header5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Header5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackLabel4 = ui_BackLabel_create(ui_Header5);
lv_obj_set_x( ui_BackLabel4, 0 );
lv_obj_set_y( ui_BackLabel4, -20 );

ui_Header_Title5 = lv_label_create(ui_Header5);
lv_obj_set_width( ui_Header_Title5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Title5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Header_Title5, 0 );
lv_obj_set_y( ui_Header_Title5, -9 );
lv_obj_set_align( ui_Header_Title5, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Header_Title5,"Logs");
lv_obj_set_style_text_color(ui_Header_Title5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Title5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Time5 = lv_label_create(ui_Header5);
lv_obj_set_width( ui_Header_Time5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Time5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Time5, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Header_Time5,"--:--:--");
lv_obj_set_style_text_color(ui_Header_Time5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Time5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button5 = lv_btn_create(ui_Header5);
lv_obj_set_width( ui_Button5, 100);
lv_obj_set_height( ui_Button5, 80);
lv_obj_set_x( ui_Button5, -10 );
lv_obj_set_y( ui_Button5, -10 );
lv_obj_add_flag( ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Button5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_Button5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaLog = lv_textarea_create(ui_Screen5);
lv_obj_set_width( ui_TextAreaLog, 310);
lv_obj_set_height( ui_TextAreaLog, 206);
lv_obj_set_x( ui_TextAreaLog, 5 );
lv_obj_set_y( ui_TextAreaLog, 29 );
lv_textarea_set_placeholder_text(ui_TextAreaLog,"Placeholder...");



lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);

}
