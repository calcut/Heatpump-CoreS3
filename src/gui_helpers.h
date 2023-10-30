#ifndef GUI_HELPERS_H
#define GUI_HELPERS_H

#include <lvgl.h>
#include <ui.h>
#include <QuickPID.h>
#include "notecard_manager.h"
#include "globals.h"

extern NotecardManager notecardManager;
extern QuickPID compressorPID;
extern db_variables_t db_vars;
extern qo_variables_t qo_vars;
extern env_variables_t env_vars;
extern bool nc_service_enable;
extern bool nc_service_tick;

void setup_gui_timers(void);
void display_notecard_info(lv_timer_t * timer);
void display_sensor_info(lv_timer_t * timer);
void display_pid_info(lv_timer_t * timer);
void display_date_time_labels(lv_timer_t * timer);
void display_log(lv_timer_t * timer);

void nc_info_screen_event_cb(lv_event_t * event);

//Timer to update date/time on screen
// void lv_timer_1s(lv_timer_t * timer);




#endif