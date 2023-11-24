#ifndef OUTPUTS_H
#define OUTPUTS_H

#ifndef COMPRESSOR_TRANSITION_TIME_MS
#define COMPRESSOR_TRANSITION_TIME_MS 3000
#endif

#define COMPRESSOR_MAX_VOLTAGE_MV 5000 //millivolts

#ifndef VALVE_TRANSITION_TIME_MS
#define VALVE_TRANSITION_TIME_MS 3000
#endif

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
        FORWARD = 1,
        REVERSE = 0
    };

    void setReversingValve(bool state);
    void setEvaporatorValve(bool state);
    void setEvaporatorBypassValve(bool state);
    void setCompressorSpeed(float percent);
    void setFanSpeed(float percent);
};

extern Outputs outputs;

#endif // OUTPUTS_H