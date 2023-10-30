#ifndef RTOS_TASKS_H
#define RTOS_TASKS_H

#include <M5Unified.h>

#include <QuickPID.h>
#include <lvgl.h>
#include <driver/pcnt.h> //ESP32 Pulse counter

#include "rtc_helpers.h"
#include "yotta_module.h"
#include "notecard_manager.h"
#include "shared_variables.h"
#include "config.h"
#include "gui_helpers.h" 

extern YottaModule yottaModule;
extern NotecardManager notecardManager;
extern QuickPID compressorPID;
extern db_variables_t db_vars;
extern qo_variables_t qo_vars;
extern env_variables_t env_vars;

extern bool nc_service_enable;
extern bool nc_service_tick;

void setup_rtos_tasks(void);

bool check_limits(void);

void poll(void * pvParameters);
void notecard_time_sync(void * pvParameters);
void notecard_service(void * pvParameters);
void control(void * pvParameters);
void state_machine(void * pvParameters);
void gui_service(void * pvParameters);
void read_pulses(void *pvParameters);

void standby_mode(void);
void discharging_mode(void);
void charging_mode(void);
void defrost_mode(void);


//These might move into the module class
void open_evaporator_valve(void);
void close_evaporator_valve(void);
void open_defrost_valve(void);
void close_defrost_valve(void);
void set_reversing_valve_forward(void);
void set_reversing_valve_reverse(void);
void set_compressor_speed(float percent); 
void set_fan_speed(float percent);

// enumerate modes for the heat pump
// standby: no heating or cooling
// charging: adding heat to flex store
// discharging: using heat from flex store
// defrost: heating evaporator from flex store

enum mode {
    STANDBY = 0,
    CHARGING = 1,
    DISCHARGING = 2,
    DEFROST = 3,
    ERROR = 4
};


#endif