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

// #include "App.h"
#include <ui.h>

#define PIN_SDA_I2C_SYS 12
#define PIN_SCL_I2C_SYS 11
#define PIN_SDA_I2C_EXT 2
#define PIN_SCL_I2C_EXT 1

#define PIN_RX_RS485 18
#define PIN_TX_RS485 17
#define PIN_DE_RS485 5
// #define PIN_PULSE_COUNT 8 // Put in rtos_tasks.cpp for now, should be moved back

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

bool nc_service_enable = true;
// bool nc_service_enable = false;
bool nc_service_tick = false;

QuickPID compressorPID(
    &qo_vars.tc[0],                     //Input
    &qo_vars.compressor_target_speed,   //Output
    &db_vars.dhw_setpoint               //Setpoint
);   

char buffer[64]; // is this used?

void setup() {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    USBSerial.begin(15200);
    M5.begin();

    Wire1.begin(PIN_SDA_I2C_SYS, PIN_SCL_I2C_SYS, 400000);  //Init I2C_SYS
    Wire.begin(PIN_SDA_I2C_EXT, PIN_SCL_I2C_EXT, 400000);  //Init I2C_EXT

    USBSerial.printf("M5CoreS3 User Demo, Version: %s\r\n", DEMO_VERSION);

    // BM8563 Init (clear INT)
    M5.In_I2C.writeRegister8(0x51, 0x00, 0x00, 100000L);
    M5.In_I2C.writeRegister8(0x51, 0x01, 0x00, 100000L);
    M5.In_I2C.writeRegister8(0x51, 0x0D, 0x00, 100000L);

    // AW9523 Control BOOST
    M5.In_I2C.bitOn(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN

    M5.Display.setBrightness(60);

    lv_init();
    m5gfx_lvgl_init();
    ui_init();

    setup_rtos_tasks();

}

void loop() {
    // Nothing here. All the work is done in the RTOS tasks

    // lv_timer_handler();
    // delay(10);
}
