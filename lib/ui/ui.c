// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: CoreS3_SLS_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen0
void ui_Screen0_screen_init(void);
lv_obj_t *ui_Screen0;
void ui_event_Button01_Button0( lv_event_t * e);
lv_obj_t *ui_Button01;
void ui_event_Button02_Button0( lv_event_t * e);
lv_obj_t *ui_Button02;
void ui_event_Button03_Button0( lv_event_t * e);
lv_obj_t *ui_Button03;
void ui_event_Button04_Button0( lv_event_t * e);
lv_obj_t *ui_Button04;
void ui_event_Button05_Button0( lv_event_t * e);
lv_obj_t *ui_Button05;
void ui_event_Button06_Button0( lv_event_t * e);
lv_obj_t *ui_Button06;
void ui_event_Button07_Button0( lv_event_t * e);
lv_obj_t *ui_Button07;
void ui_event_Button08_Button0( lv_event_t * e);
lv_obj_t *ui_Button08;
void ui_event_Button09_Button0( lv_event_t * e);
lv_obj_t *ui_Button09;


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Header1;
lv_obj_t *ui_BackLabel;
lv_obj_t *ui_Header_Title1;
lv_obj_t *ui_Header_Time1;
lv_obj_t *ui_Arc_Group;
lv_obj_t *ui_Label2;
void ui_event_Arc1( lv_event_t * e);
lv_obj_t *ui_Arc1;
lv_obj_t *ui_Label_Celsius;
void ui_event_Fan_Speed_Control( lv_event_t * e);
lv_obj_t *ui_Fan_Speed_Control;
lv_obj_t *ui_Label_Slider;
void ui_event_Button1( lv_event_t * e);
lv_obj_t *ui_Button1;


// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
lv_obj_t *ui_Screen2;
lv_obj_t *ui_Header2;
lv_obj_t *ui_BackLabel1;
lv_obj_t *ui_Header_Time2;
lv_obj_t *ui_Header_Title2;
lv_obj_t *ui_Panel2_sensor1;
lv_obj_t *ui_Bar2_value1;
lv_obj_t *ui_Label2_value1;
lv_obj_t *ui_Label2_name1;
lv_obj_t *ui_Panel2_sensor2;
lv_obj_t *ui_Bar2_value2;
lv_obj_t *ui_Label2_value2;
lv_obj_t *ui_Label2_name2;
lv_obj_t *ui_Panel2_sensor3;
lv_obj_t *ui_Bar2_value3;
lv_obj_t *ui_Label2_value3;
lv_obj_t *ui_Label2_name3;
lv_obj_t *ui_Panel2_sensor4;
lv_obj_t *ui_Bar2_value4;
lv_obj_t *ui_Label2_value4;
lv_obj_t *ui_Label2_name4;
lv_obj_t *ui_Panel2_sensor5;
lv_obj_t *ui_Bar2_value5;
lv_obj_t *ui_Label2_value5;
lv_obj_t *ui_Label2_name5;
lv_obj_t *ui_Panel2_sensor6;
lv_obj_t *ui_Bar2_value6;
lv_obj_t *ui_Label2_value6;
lv_obj_t *ui_Label2_name6;
lv_obj_t *ui_Panel2_sensor7;
lv_obj_t *ui_Bar2_value7;
lv_obj_t *ui_Label2_value7;
lv_obj_t *ui_Label2_name7;
lv_obj_t *ui_Panel2_sensor8;
lv_obj_t *ui_Bar2_value8;
lv_obj_t *ui_Label2_value8;
lv_obj_t *ui_Label2_name8;
void ui_event_Button2( lv_event_t * e);
lv_obj_t *ui_Button2;


// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
lv_obj_t *ui_Screen3;
lv_obj_t *ui_Header3;
lv_obj_t *ui_BackLabel2;
lv_obj_t *ui_Header_Title3;
lv_obj_t *ui_Header_Time3;
lv_obj_t *ui_Bar1;
lv_obj_t *ui_Bar2;
lv_obj_t *ui_Bar3;
lv_obj_t *ui_Bar4;
lv_obj_t *ui_LabelRSSI;
lv_obj_t *ui_LabelConnected;
lv_obj_t *ui_LabelBand;
lv_obj_t *ui_LabelRat;
lv_obj_t *ui_LabelSerial;
lv_obj_t *ui_LabelSyncStatus;
lv_obj_t *ui_LabelDevice;
lv_obj_t *ui_LabelHubStatus;
lv_obj_t *ui_TextAreaHubStatus;
lv_obj_t *ui_TextAreaSyncStatus;
lv_obj_t *ui_Button3_Refresh;
lv_obj_t *ui_Label3_Refresh;
void ui_event_Button3( lv_event_t * e);
lv_obj_t *ui_Button3;


// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
lv_obj_t *ui_Screen4;
lv_obj_t *ui_Header4;
lv_obj_t *ui_BackLabel3;
lv_obj_t *ui_Header_Title4;
lv_obj_t *ui_Header_Time4;
lv_obj_t *ui_Panel4_Kp;
lv_obj_t *ui_Label4_Kp;
lv_obj_t *ui_Label4_Kp_val;
lv_obj_t *ui_Panel4_Ki;
lv_obj_t *ui_Label4_Ki;
lv_obj_t *ui_Label4_Ki_val;
lv_obj_t *ui_Panel4_Kd;
lv_obj_t *ui_Label4_Kd;
lv_obj_t *ui_Label4_Kd_val;
lv_obj_t *ui_Panel4_In;
lv_obj_t *ui_Label4_inplus;
lv_obj_t *ui_Panel4_Out;
lv_obj_t *ui_Label4_outplus;
lv_obj_t *ui_Label4_Error;
lv_obj_t *ui_Label4_Error_val;
lv_obj_t *ui_Label4_Output;
lv_obj_t *ui_Label4_Setpoint;
lv_obj_t *ui_Label4_Setpoint_val;
lv_obj_t *ui_Label4_Input;
lv_obj_t *ui_Label4_Input_val;
lv_obj_t *ui_Label4_Pterm;
lv_obj_t *ui_Label4_Dterm;
lv_obj_t *ui_Label4_Iterm;
lv_obj_t *ui_Label4_Iterm_val;
lv_obj_t *ui_Label4_Output_val;
lv_obj_t *ui_Label4_Pterm_val;
lv_obj_t *ui_Label4_Dterm_val;
void ui_event_Button4( lv_event_t * e);
lv_obj_t *ui_Button4;


// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
lv_obj_t *ui_Screen5;
lv_obj_t *ui_Header5;
lv_obj_t *ui_BackLabel4;
lv_obj_t *ui_Header_Title5;
lv_obj_t *ui_Header_Time5;
lv_obj_t *ui_TextAreaLog;
void ui_event_Button5( lv_event_t * e);
lv_obj_t *ui_Button5;


// SCREEN: ui_Screen6
void ui_Screen6_screen_init(void);
lv_obj_t *ui_Screen6;
lv_obj_t *ui_Chart1;
lv_obj_t *ui_Header6;
lv_obj_t *ui_BackLabel5;
lv_obj_t *ui_Header_Title6;
lv_obj_t *ui_Header_Time6;
void ui_event_Button6( lv_event_t * e);
lv_obj_t *ui_Button6;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button01_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen1_screen_init);
}
}
void ui_event_Button02_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen2_screen_init);
}
}
void ui_event_Button03_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen3_screen_init);
}
}
void ui_event_Button04_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen4, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen4_screen_init);
}
}
void ui_event_Button05_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen5, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen5_screen_init);
}
}
void ui_event_Button06_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen6, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen6_screen_init);
}
}
void ui_event_Button07_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen3_screen_init);
}
}
void ui_event_Button08_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen3_screen_init);
}
}
void ui_event_Button09_Button0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Screen3_screen_init);
}
}
void ui_event_Arc1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_arc_set_text_value( ui_Label_Celsius, target, "", "°");
}
}
void ui_event_Fan_Speed_Control( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      fan_speed_value( e );
}
}
void ui_event_Button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}
void ui_event_Button2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}
void ui_event_Button3( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}
void ui_event_Button4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}
void ui_event_Button5( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}
void ui_event_Button6( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen0, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0, &ui_Screen0_screen_init);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen0_screen_init();
ui_Screen1_screen_init();
ui_Screen2_screen_init();
ui_Screen3_screen_init();
ui_Screen4_screen_init();
ui_Screen5_screen_init();
ui_Screen6_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen0);
}
