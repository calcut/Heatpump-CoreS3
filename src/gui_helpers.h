#ifndef GUI_HELPERS_H
#define GUI_HELPERS_H

#include <lvgl.h>
#include <ui.h>
#include <QuickPID.h>
#include "notecard_manager.h"
#include "shared_variables.h"

#define TERMINAL_LOG_LENGTH  512        /*Characters*/

extern NotecardManager notecardManager;
extern QuickPID compressorPID;
extern db_variables_t db_vars;
extern qo_variables_t qo_vars;
extern env_variables_t env_vars;
extern bool nc_service_enable;
extern bool nc_service_tick;

static char txt_log[TERMINAL_LOG_LENGTH + 1];

void setup_gui_timers(void);
void display_notecard_info(lv_timer_t * timer);
void display_sensor_info(lv_timer_t * timer);
void display_pid_info(lv_timer_t * timer);
void display_date_time_labels(lv_timer_t * timer);

void nc_info_screen_event_cb(lv_event_t * event);

//Timer to update date/time on screen
// void lv_timer_1s(lv_timer_t * timer);

class SerialDisplay : public HWCDC
//https://stackoverflow.com/questions/60972073/customizing-the-standard-serial-print-functions-in-arduino
{
    using HWCDC::HWCDC; // Inherit constructors
    public:
        size_t write(const uint8_t *buffer, size_t size) override;   // Overriding base functionality
};
extern SerialDisplay serialDisplay;


#endif