#ifndef EVD_MODULE_H
#define EVD_MODULE_H

#define EVD_S1_READ 0
#define EVD_S2_READ 1
#define EVD_S3_READ 2
#define EVD_S4_READ 3
#define EVD_FIRMWARE_VERSION 24
#define EVD_NETWORK_SETTINGS 201
#define EVD_NETWORK_ADDRESS 138

#define EVD_S1_CONFIG 143
#define EVD_S2_CONFIG 144
#define EVD_S3_CONFIG 146
#define EVD_S4_CONFIG 147

#define EVD_REFRIGERANT_TYPE 140
#define EVD_MAIN_CONTROL 142

#ifndef EVD_MODULE_ADDRESS
#define EVD_MODULE_ADDRESS 198
#endif

#include <Arduino.h>
#include <ArduinoModbus.h>
#include "config.h"

class EvdModule {

    private:
        int slave_id = EVD_MODULE_ADDRESS;
        void writeRegister(int reg, int value);

    public:
        void getSensors(float *sensors);
        void init();
        void resetNetworkSettings();
        void updateNetworkSettings();
};

#endif