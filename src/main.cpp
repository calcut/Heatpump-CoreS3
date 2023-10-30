#include <Arduino.h>
#include <FFat.h>
#include <Wire.h>
// #include <BLEDevice.h>
#include <nvs_flash.h>

#include "config.h"
#include "M5GFX.h"
#include "M5Unified.h"
#include "lvgl.h"
#include "m5gfx_lvgl.h"
// #include "esp_camera.h"

#include "notecard_manager.h"
#include "rtos_tasks.h"
#include "gui_helpers.h" 
#include "rtc_helpers.h" 

// #include "App.h"
#include <ui.h>

#define YOTTA_MODULE_ID 0
#define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)

#define NC_SYNC true
#define NC_MODE "continuous"
#define NC_INBOUND 1
#define NC_OUTBOUND 1
#define NC_UID "dwt.ac.uk.heatpump"

#define FLOAT_DECIMALS 1

RS485Class RS485(Serial2, PIN_RX_RS485, PIN_TX_RS485, PIN_DE_RS485, -1);
NotecardManager notecardManager;
YottaModule yottaModule(YOTTA_MODULE_ID);

uint32_t currentMs = millis();

db_variables_t db_vars;
qo_variables_t qo_vars;
env_variables_t env_vars;

bool nc_service_enable = false;
bool nc_service_tick = false;

QuickPID compressorPID(
    &qo_vars.tc[0],                     //Input
    &qo_vars.compressor_target_speed,   //Output
    &db_vars.dhw_setpoint               //Setpoint
);   

void setup() {

    //Default is all 3 options disabled, AKA POWER_MODE_USB_IN_BUS_IN
    M5.In_I2C.bitOff(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN = 1

    M5.In_I2C.bitOff(AW9523_ADDR, 0x02, 0b00000010, 100000L);  // BUS_OUT_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x02, 0b00000010, 100000L);  // BUS_OUT_EN = 1

    M5.In_I2C.bitOff(AW9523_ADDR, 0x02, 0b00100000, 100000L);  // USB_OTG_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x02, 0b00100000, 100000L);  // USB_OTG_EN = 1

    USBSerial.begin();
    while (!USBSerial) {
    ; // wait for serial port to connect. Needed for native USB
    }
    M5.begin();

    Wire.begin(PIN_SDA_I2C_EXT, PIN_SCL_I2C_EXT, 400000);  //Init I2C_EXT
    notecardManager.begin();

    USBSerial.printf("M5CoreS3 User Demo, Version: %s\r\n", DEMO_VERSION);
    M5.Display.setBrightness(60);

    lv_init();
    m5gfx_lvgl_init();
    ui_init();
    setup_gui_timers();
    setup_rtos_tasks();



}

void loop() {
    // Nothing here. All the work is done in the RTOS tasks
}
