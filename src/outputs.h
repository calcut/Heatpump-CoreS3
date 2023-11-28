#ifndef OUTPUTS_H
#define OUTPUTS_H

#ifndef COMPRESSOR_TRANSITION_TIME_MS
#define COMPRESSOR_TRANSITION_TIME_MS 3000
#endif

#define COMPRESSOR_MAX_VOLTAGE_MV 5000 //millivolts
#define FAN_MAX_VOLTAGE_MV 5000 //millivolts

#ifndef VALVE_TRANSITION_TIME_MS
#define VALVE_TRANSITION_TIME_MS 3000
#endif

#define EVAPORATOR_VALVE_RELAY 2
#define EVAPORATOR_BYPASS_VALVE_RELAY 3
#define REVERSING_VALVE_RELAY 1

#include "mod_16ro.h"
#include "mod_8ao.h"

class Outputs {
public:

    Mod_16RO mod_16RO;
    Mod_8AO mod_8AO;

    enum ValveState {
        OPEN = 1,
        CLOSED = 0
    };
    enum ReversingValveState {
        FORWARD = 0,
        REVERSE = 1
    };

    void init();
    void feedWatchdogs();
    void setReversingValve(ReversingValveState state);
    void setEvaporatorValve(ValveState state);
    void setEvaporatorBypassValve(ValveState state);
    void setCompressorSpeed(float percent);
    void setFanSpeed(float percent);
};

extern Outputs outputs;

#endif // OUTPUTS_H