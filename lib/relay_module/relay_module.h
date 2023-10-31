#ifndef RELAY_MODULE_H
#define RELAY_MODULE_H

// If these don't work try adding 1 to the address
#define MODULE_NAME_ADDR 0
#define OUTPUTS_ADDR 12
#define WATCHDOG_ADDR 8
#define OUTPUT_DEFAULTS_ADDR 12
#define OUTPUTS_ADDR 51




#include <Arduino.h>
#include <ArduinoModbus.h>

class RelayModule {

    private:
        int slave_id;

    public:
        RelayModule(int slave_id);
        void setRelays(bool *relays);
        void getRelays(bool *relays);
        void setRelayDefaults(bool *relay_defaults);
        void getRelayDefaults(bool *relay_defaults);
        void setWatchdog(int16_t watchdog_ms);
        void init(bool *relay_defaults);
};

#endif