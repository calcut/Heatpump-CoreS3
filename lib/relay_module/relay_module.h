#ifndef RELAY_MODULE_H
#define RELAY_MODULE_H

#define RELAY_VERSION 0
#define RELAY_WATCHDOG 8
#define RELAY_OUTPUT_DEFAULTS 12
#define RELAY_OUTPUTS 51

#ifndef RELAY_MODULE_ADDRESS
#define RELAY_MODULE_ADDRESS 2
#endif

#include <Arduino.h>
#include <ArduinoModbus.h>

class RelayModule {

    private:
        int slave_id = RELAY_MODULE_ADDRESS;

    public:
        void setRelays(bool *relays);
        void getRelays(bool *relays);
        void setRelayDefaults(bool *relay_defaults);
        void getRelayDefaults(bool *relay_defaults);
        void setWatchdog(int16_t watchdog_ms);
        void init(bool *relay_defaults);
};

#endif