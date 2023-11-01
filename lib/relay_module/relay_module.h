#ifndef RELAY_MODULE_H
#define RELAY_MODULE_H

// If these don't work try adding 1 to the address
#define RELAY_VERSION 0
#define RELAY_WATCHDOG 8
#define RELAY_OUTPUT_DEFAULTS 12
#define RELAY_OUTPUTS 51


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