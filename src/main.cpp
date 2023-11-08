// #include <Arduino.h>

#include "config.h"
#include "hal_coreS3.h"
#include "rtos_tasks.h"

#define USE_GUI

#ifdef USE_GUI
#include "gui_helpers.h"
#endif


void setup() {

    hal_setup();

    // For DEBUG ONLY, otherwise comment out so it can boot without a USB cable
    // while (!USBSerial) {
    // ; // wait for serial port to connect.
    // }

    notecardManager.begin(serialDisplay);

    #ifdef USE_GUI
    setupGui();
    #endif
    
    setupRtos();
}

void loop() {
    // Nothing here. All the work is done in the RTOS tasks
}
