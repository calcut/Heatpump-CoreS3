#ifndef OUTPUTS_H
#define OUTPUTS_H

#ifndef COMPRESSOR_TRANSITION_TIME_MS
#define COMPRESSOR_TRANSITION_TIME_MS 3000
#endif

#ifndef VALVE_TRANSITION_TIME_MS
#define VALVE_TRANSITION_TIME_MS 3000
#endif

#include "relay_module.h"
// #include "analog_IO.h"


class Outputs {
public:

    RelayModule relayModule;

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