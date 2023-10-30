// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: CoreS3_SLS_Project

#include "../ui.h"

void ui_Screen2_screen_init(void)
{
ui_Screen2 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Header2 = lv_obj_create(ui_Screen2);
lv_obj_set_height( ui_Header2, 25);
lv_obj_set_width( ui_Header2, lv_pct(100));
lv_obj_set_align( ui_Header2, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_Header2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Header2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Header2, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Header2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Header2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BackLabel1 = ui_BackLabel_create(ui_Header2);
lv_obj_set_x( ui_BackLabel1, 0 );
lv_obj_set_y( ui_BackLabel1, -20 );

ui_Header_Time2 = lv_label_create(ui_Header2);
lv_obj_set_width( ui_Header_Time2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Time2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Time2, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Header_Time2,"--:--:--");
lv_obj_set_style_text_color(ui_Header_Time2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Time2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Title2 = lv_label_create(ui_Header2);
lv_obj_set_width( ui_Header_Title2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Title2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Header_Title2, 0 );
lv_obj_set_y( ui_Header_Title2, -9 );
lv_obj_set_align( ui_Header_Title2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Header_Title2,"Temperature & Pressure");
lv_label_set_recolor(ui_Header_Title2,"true");
lv_obj_set_style_text_color(ui_Header_Title2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Title2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button2 = lv_btn_create(ui_Header2);
lv_obj_set_width( ui_Button2, 100);
lv_obj_set_height( ui_Button2, 80);
lv_obj_set_x( ui_Button2, -10 );
lv_obj_set_y( ui_Button2, -10 );
lv_obj_add_flag( ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Button2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Button2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_Button2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_Button2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel2_sensor1 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor1, 320);
lv_obj_set_height( ui_Panel2_sensor1, 25);
lv_obj_set_x( ui_Panel2_sensor1, 0 );
lv_obj_set_y( ui_Panel2_sensor1, 25 );
lv_obj_clear_flag( ui_Panel2_sensor1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value1 = lv_bar_create(ui_Panel2_sensor1);
lv_bar_set_range(ui_Bar2_value1, -10,50);
lv_obj_set_width( ui_Bar2_value1, 95);
lv_obj_set_height( ui_Bar2_value1, 10);
lv_obj_set_x( ui_Bar2_value1, 60 );
lv_obj_set_y( ui_Bar2_value1, -7 );

ui_Label2_value1 = lv_label_create(ui_Panel2_sensor1);
lv_obj_set_width( ui_Label2_value1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value1, -2 );
lv_obj_set_y( ui_Label2_value1, -10 );
lv_label_set_text(ui_Label2_value1," 0.0 °C");

ui_Label2_name1 = lv_label_create(ui_Panel2_sensor1);
lv_obj_set_width( ui_Label2_name1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name1, 165 );
lv_obj_set_y( ui_Label2_name1, -10 );
lv_label_set_text(ui_Label2_name1,"Compressor Inlet");

ui_Panel2_sensor2 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor2, 320);
lv_obj_set_height( ui_Panel2_sensor2, 25);
lv_obj_set_x( ui_Panel2_sensor2, 0 );
lv_obj_set_y( ui_Panel2_sensor2, 50 );
lv_obj_clear_flag( ui_Panel2_sensor2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value2 = lv_bar_create(ui_Panel2_sensor2);
lv_bar_set_range(ui_Bar2_value2, -10,50);
lv_obj_set_width( ui_Bar2_value2, 95);
lv_obj_set_height( ui_Bar2_value2, 10);
lv_obj_set_x( ui_Bar2_value2, 60 );
lv_obj_set_y( ui_Bar2_value2, -7 );

ui_Label2_value2 = lv_label_create(ui_Panel2_sensor2);
lv_obj_set_width( ui_Label2_value2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value2, -2 );
lv_obj_set_y( ui_Label2_value2, -10 );
lv_label_set_text(ui_Label2_value2," 0.0 °C");

ui_Label2_name2 = lv_label_create(ui_Panel2_sensor2);
lv_obj_set_width( ui_Label2_name2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name2, 165 );
lv_obj_set_y( ui_Label2_name2, -10 );
lv_label_set_text(ui_Label2_name2,"Compressor Out");

ui_Panel2_sensor3 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor3, 320);
lv_obj_set_height( ui_Panel2_sensor3, 25);
lv_obj_set_x( ui_Panel2_sensor3, 0 );
lv_obj_set_y( ui_Panel2_sensor3, 75 );
lv_obj_clear_flag( ui_Panel2_sensor3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value3 = lv_bar_create(ui_Panel2_sensor3);
lv_bar_set_range(ui_Bar2_value3, -10,50);
lv_obj_set_width( ui_Bar2_value3, 96);
lv_obj_set_height( ui_Bar2_value3, 10);
lv_obj_set_x( ui_Bar2_value3, 60 );
lv_obj_set_y( ui_Bar2_value3, -7 );

ui_Label2_value3 = lv_label_create(ui_Panel2_sensor3);
lv_obj_set_width( ui_Label2_value3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value3, -2 );
lv_obj_set_y( ui_Label2_value3, -10 );
lv_label_set_text(ui_Label2_value3," 0.0 °C");

ui_Label2_name3 = lv_label_create(ui_Panel2_sensor3);
lv_obj_set_width( ui_Label2_name3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name3, 165 );
lv_obj_set_y( ui_Label2_name3, -10 );
lv_label_set_text(ui_Label2_name3,"Condenser Out");

ui_Panel2_sensor4 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor4, 320);
lv_obj_set_height( ui_Panel2_sensor4, 25);
lv_obj_set_x( ui_Panel2_sensor4, 0 );
lv_obj_set_y( ui_Panel2_sensor4, 100 );
lv_obj_clear_flag( ui_Panel2_sensor4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value4 = lv_bar_create(ui_Panel2_sensor4);
lv_bar_set_range(ui_Bar2_value4, -10,50);
lv_obj_set_width( ui_Bar2_value4, 95);
lv_obj_set_height( ui_Bar2_value4, 10);
lv_obj_set_x( ui_Bar2_value4, 60 );
lv_obj_set_y( ui_Bar2_value4, -7 );

ui_Label2_value4 = lv_label_create(ui_Panel2_sensor4);
lv_obj_set_width( ui_Label2_value4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value4, -2 );
lv_obj_set_y( ui_Label2_value4, -10 );
lv_label_set_text(ui_Label2_value4," 0.0 °C");

ui_Label2_name4 = lv_label_create(ui_Panel2_sensor4);
lv_obj_set_width( ui_Label2_name4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name4, 165 );
lv_obj_set_y( ui_Label2_name4, -10 );
lv_label_set_text(ui_Label2_name4,"Flex Store Refr");

ui_Panel2_sensor5 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor5, 320);
lv_obj_set_height( ui_Panel2_sensor5, 25);
lv_obj_set_x( ui_Panel2_sensor5, 0 );
lv_obj_set_y( ui_Panel2_sensor5, 125 );
lv_obj_clear_flag( ui_Panel2_sensor5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value5 = lv_bar_create(ui_Panel2_sensor5);
lv_bar_set_range(ui_Bar2_value5, -10,50);
lv_obj_set_width( ui_Bar2_value5, 95);
lv_obj_set_height( ui_Bar2_value5, 10);
lv_obj_set_x( ui_Bar2_value5, 60 );
lv_obj_set_y( ui_Bar2_value5, -7 );

ui_Label2_value5 = lv_label_create(ui_Panel2_sensor5);
lv_obj_set_width( ui_Label2_value5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value5, -2 );
lv_obj_set_y( ui_Label2_value5, -10 );
lv_label_set_text(ui_Label2_value5," 0.0 °C");

ui_Label2_name5 = lv_label_create(ui_Panel2_sensor5);
lv_obj_set_width( ui_Label2_name5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name5, 165 );
lv_obj_set_y( ui_Label2_name5, -10 );
lv_label_set_text(ui_Label2_name5,"Flex Store Water");

ui_Panel2_sensor6 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor6, 320);
lv_obj_set_height( ui_Panel2_sensor6, 25);
lv_obj_set_x( ui_Panel2_sensor6, 0 );
lv_obj_set_y( ui_Panel2_sensor6, 150 );
lv_obj_clear_flag( ui_Panel2_sensor6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value6 = lv_bar_create(ui_Panel2_sensor6);
lv_bar_set_range(ui_Bar2_value6, -10,50);
lv_obj_set_width( ui_Bar2_value6, 95);
lv_obj_set_height( ui_Bar2_value6, 10);
lv_obj_set_x( ui_Bar2_value6, 60 );
lv_obj_set_y( ui_Bar2_value6, -7 );

ui_Label2_value6 = lv_label_create(ui_Panel2_sensor6);
lv_obj_set_width( ui_Label2_value6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value6, -2 );
lv_obj_set_y( ui_Label2_value6, -10 );
lv_label_set_text(ui_Label2_value6," 0.0 °C");

ui_Label2_name6 = lv_label_create(ui_Panel2_sensor6);
lv_obj_set_width( ui_Label2_name6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name6, 165 );
lv_obj_set_y( ui_Label2_name6, -10 );
lv_label_set_text(ui_Label2_name6,"Ambient (Air)");

ui_Panel2_sensor7 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor7, 320);
lv_obj_set_height( ui_Panel2_sensor7, 25);
lv_obj_set_x( ui_Panel2_sensor7, 0 );
lv_obj_set_y( ui_Panel2_sensor7, 175 );
lv_obj_clear_flag( ui_Panel2_sensor7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value7 = lv_bar_create(ui_Panel2_sensor7);
lv_bar_set_range(ui_Bar2_value7, -10,50);
lv_obj_set_width( ui_Bar2_value7, 95);
lv_obj_set_height( ui_Bar2_value7, 10);
lv_obj_set_x( ui_Bar2_value7, 60 );
lv_obj_set_y( ui_Bar2_value7, -7 );
lv_obj_set_style_bg_color(ui_Bar2_value7, lv_color_hex(0xDE9500), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2_value7, 32, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Bar2_value7, lv_color_hex(0xDE9500), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2_value7, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_Label2_value7 = lv_label_create(ui_Panel2_sensor7);
lv_obj_set_width( ui_Label2_value7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value7, -2 );
lv_obj_set_y( ui_Label2_value7, -10 );
lv_label_set_text(ui_Label2_value7," 0.0 Bar");

ui_Label2_name7 = lv_label_create(ui_Panel2_sensor7);
lv_obj_set_width( ui_Label2_name7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name7, 165 );
lv_obj_set_y( ui_Label2_name7, -10 );
lv_label_set_text(ui_Label2_name7,"Compressor Inlet");

ui_Panel2_sensor8 = lv_obj_create(ui_Screen2);
lv_obj_set_width( ui_Panel2_sensor8, 320);
lv_obj_set_height( ui_Panel2_sensor8, 25);
lv_obj_set_x( ui_Panel2_sensor8, 0 );
lv_obj_set_y( ui_Panel2_sensor8, 200 );
lv_obj_clear_flag( ui_Panel2_sensor8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2_sensor8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2_sensor8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2_sensor8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2_sensor8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2_value8 = lv_bar_create(ui_Panel2_sensor8);
lv_bar_set_range(ui_Bar2_value8, -10,50);
lv_obj_set_width( ui_Bar2_value8, 95);
lv_obj_set_height( ui_Bar2_value8, 10);
lv_obj_set_x( ui_Bar2_value8, 60 );
lv_obj_set_y( ui_Bar2_value8, -7 );
lv_obj_set_style_bg_color(ui_Bar2_value8, lv_color_hex(0xDE9500), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2_value8, 32, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Bar2_value8, lv_color_hex(0xDE9500), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2_value8, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_Label2_value8 = lv_label_create(ui_Panel2_sensor8);
lv_obj_set_width( ui_Label2_value8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_value8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_value8, -2 );
lv_obj_set_y( ui_Label2_value8, -10 );
lv_label_set_text(ui_Label2_value8," 0.0 Bar");

ui_Label2_name8 = lv_label_create(ui_Panel2_sensor8);
lv_obj_set_width( ui_Label2_name8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2_name8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2_name8, 165 );
lv_obj_set_y( ui_Label2_name8, -10 );
lv_label_set_text(ui_Label2_name8,"Compressor Out");

lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);

}
