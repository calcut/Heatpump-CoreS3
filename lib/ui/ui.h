// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: CoreS3_SLS_Project

#ifndef _CORES3_SLS_PROJECT_UI_H
#define _CORES3_SLS_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"
// SCREEN: ui_Screen0
void ui_Screen0_screen_init(void);
extern lv_obj_t *ui_Screen0;
void ui_event_Button01_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button01;
void ui_event_Button02_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button02;
void ui_event_Button03_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button03;
void ui_event_Button04_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button04;
void ui_event_Button05_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button05;
void ui_event_Button06_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button06;
void ui_event_Button07_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button07;
void ui_event_Button08_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button08;
void ui_event_Button09_Button0( lv_event_t * e);
extern lv_obj_t *ui_Button09;
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_Header1;
extern lv_obj_t *ui_BackLabel;
extern lv_obj_t *ui_Header_Title1;
extern lv_obj_t *ui_Header_Time1;
void ui_event_Button1( lv_event_t * e);
extern lv_obj_t *ui_Button1;
extern lv_obj_t *ui_Arc_Group;
extern lv_obj_t *ui_Label2;
void ui_event_Arc1( lv_event_t * e);
extern lv_obj_t *ui_Arc1;
extern lv_obj_t *ui_Label_Celsius;
void ui_event_Fan_Speed_Control( lv_event_t * e);
extern lv_obj_t *ui_Fan_Speed_Control;
extern lv_obj_t *ui_Label_Slider;
// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
extern lv_obj_t *ui_Screen2;
extern lv_obj_t *ui_Header2;
extern lv_obj_t *ui_BackLabel1;
extern lv_obj_t *ui_Header_Time2;
extern lv_obj_t *ui_Header_Title2;
void ui_event_Button2( lv_event_t * e);
extern lv_obj_t *ui_Button2;
extern lv_obj_t *ui_Panel2_sensor1;
extern lv_obj_t *ui_Bar2_value1;
extern lv_obj_t *ui_Label2_value1;
extern lv_obj_t *ui_Label2_name1;
extern lv_obj_t *ui_Panel2_sensor2;
extern lv_obj_t *ui_Bar2_value2;
extern lv_obj_t *ui_Label2_value2;
extern lv_obj_t *ui_Label2_name2;
extern lv_obj_t *ui_Panel2_sensor3;
extern lv_obj_t *ui_Bar2_value3;
extern lv_obj_t *ui_Label2_value3;
extern lv_obj_t *ui_Label2_name3;
extern lv_obj_t *ui_Panel2_sensor4;
extern lv_obj_t *ui_Bar2_value4;
extern lv_obj_t *ui_Label2_value4;
extern lv_obj_t *ui_Label2_name4;
extern lv_obj_t *ui_Panel2_sensor5;
extern lv_obj_t *ui_Bar2_value5;
extern lv_obj_t *ui_Label2_value5;
extern lv_obj_t *ui_Label2_name5;
extern lv_obj_t *ui_Panel2_sensor6;
extern lv_obj_t *ui_Bar2_value6;
extern lv_obj_t *ui_Label2_value6;
extern lv_obj_t *ui_Label2_name6;
extern lv_obj_t *ui_Panel2_sensor7;
extern lv_obj_t *ui_Bar2_value7;
extern lv_obj_t *ui_Label2_value7;
extern lv_obj_t *ui_Label2_name7;
extern lv_obj_t *ui_Panel2_sensor8;
extern lv_obj_t *ui_Bar2_value8;
extern lv_obj_t *ui_Label2_value8;
extern lv_obj_t *ui_Label2_name8;
// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
extern lv_obj_t *ui_Screen3;
extern lv_obj_t *ui_Bar1;
extern lv_obj_t *ui_Header3;
extern lv_obj_t *ui_BackLabel2;
extern lv_obj_t *ui_Header_Title3;
extern lv_obj_t *ui_Header_Time3;
void ui_event_Button3( lv_event_t * e);
extern lv_obj_t *ui_Button3;
extern lv_obj_t *ui_Bar2;
extern lv_obj_t *ui_Bar3;
extern lv_obj_t *ui_Bar4;
extern lv_obj_t *ui_LabelRSSI;
extern lv_obj_t *ui_LabelConnected;
extern lv_obj_t *ui_LabelBand;
extern lv_obj_t *ui_LabelRat;
extern lv_obj_t *ui_LabelSerial;
extern lv_obj_t *ui_LabelSyncStatus;
extern lv_obj_t *ui_LabelDevice;
extern lv_obj_t *ui_LabelHubStatus;
extern lv_obj_t *ui_TextAreaHubStatus;
extern lv_obj_t *ui_TextAreaSyncStatus;
extern lv_obj_t *ui_Button3_Refresh;
extern lv_obj_t *ui_Label3_Refresh;
// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
extern lv_obj_t *ui_Screen4;
extern lv_obj_t *ui_Header4;
void ui_event_Button4( lv_event_t * e);
extern lv_obj_t *ui_Button4;
extern lv_obj_t *ui_BackLabel3;
extern lv_obj_t *ui_Header_Title4;
extern lv_obj_t *ui_Header_Time4;
extern lv_obj_t *ui_Panel4_Kp;
extern lv_obj_t *ui_Label4_Kp;
extern lv_obj_t *ui_Label4_Kp_val;
extern lv_obj_t *ui_Panel4_Ki;
extern lv_obj_t *ui_Label4_Ki;
extern lv_obj_t *ui_Label4_Ki_val;
extern lv_obj_t *ui_Panel4_Kd;
extern lv_obj_t *ui_Label4_Kd;
extern lv_obj_t *ui_Label4_Kd_val;
extern lv_obj_t *ui_Panel4_In;
extern lv_obj_t *ui_Label4_inplus;
extern lv_obj_t *ui_Panel4_Out;
extern lv_obj_t *ui_Label4_outplus;
extern lv_obj_t *ui_Label4_Error;
extern lv_obj_t *ui_Label4_Error_val;
extern lv_obj_t *ui_Label4_Output;
extern lv_obj_t *ui_Label4_Setpoint;
extern lv_obj_t *ui_Label4_Setpoint_val;
extern lv_obj_t *ui_Label4_Input;
extern lv_obj_t *ui_Label4_Input_val;
extern lv_obj_t *ui_Label4_Pterm;
extern lv_obj_t *ui_Label4_Dterm;
extern lv_obj_t *ui_Label4_Iterm;
extern lv_obj_t *ui_Label4_Iterm_val;
extern lv_obj_t *ui_Label4_Output_val;
extern lv_obj_t *ui_Label4_Pterm_val;
extern lv_obj_t *ui_Label4_Dterm_val;
// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
extern lv_obj_t *ui_Screen5;
extern lv_obj_t *ui_Header5;
extern lv_obj_t *ui_BackLabel4;
extern lv_obj_t *ui_Header_Title5;
extern lv_obj_t *ui_Header_Time5;
void ui_event_Button5( lv_event_t * e);
extern lv_obj_t *ui_Button5;
extern lv_obj_t *ui_TextAreaLog;
extern lv_obj_t *ui____initial_actions0;



LV_FONT_DECLARE( ui_font_Number);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
