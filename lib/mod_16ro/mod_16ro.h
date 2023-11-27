#ifndef MOD_16RO_H
#define MOD_16RO_H

#define MOD_16RO_VERSION 0
#define MOD_16RO_WATCHDOG 8
#define MOD_16RO_OUTPUT_DEFAULTS 12
#define MOD_16RO_OUTPUTS 51

#ifndef MOD_16RO_ADDRESS
#define MOD_16RO_ADDRESS 2
#endif

#include <Arduino.h>
#include <ArduinoModbus.h>

class Mod_16RO {

    private:
        int id = MOD_16RO_ADDRESS;

    public:
        void init();
        void setRelays(bool *relays);
        void getRelays(bool *relays);
        void setRelayDefaults(bool *relay_defaults);
        void getRelayDefaults(bool *relay_defaults);
        void setWatchdog(int16_t watchdog_ms);
};

#endif