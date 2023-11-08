#ifndef RTOS_TASKS_H
#define RTOS_TASKS_H

#include <M5Unified.h>
#include <lvgl.h>

#include "rtc_helpers.h"
#include "state_machine.h"
#include "notecard_manager.h"
#include "config.h"

#ifdef USE_GUI
#include "gui_helpers.h" 
#endif

void setupRtos(void);

void timeSyncNotecard(void * pvParameters);
void serviceNotecard(void * pvParameters);
void debugTask(void * pvParameters);
void runStateMachine(void * pvParameters);
void serviceGUI(void * pvParameters);
void readFlowMeters(void *pvParameters);
void computePID(void *pvParameters);


#endif