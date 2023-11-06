#ifndef RTOS_TASKS_H
#define RTOS_TASKS_H

#include <M5Unified.h>

#include <lvgl.h>
#include <driver/pcnt.h> //ESP32 Pulse counter

#include "rtc_helpers.h"

#include "state_machine.h"

#include "notecard_manager.h"

#include "config.h"
#include "gui_helpers.h" 

extern NotecardManager notecardManager;

extern bool nc_service_enable;
extern bool nc_service_tick;

void setup_rtos_tasks(void);


void pollInputs(void * pvParameters);
void notecard_time_sync(void * pvParameters);
void notecard_service(void * pvParameters);
void control(void * pvParameters);
void runStateMachine(void * pvParameters);
void gui_service(void * pvParameters);
void read_pulses(void *pvParameters);
void computePID(void *pvParameters);


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