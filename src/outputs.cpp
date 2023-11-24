
#include "outputs.h"

Outputs outputs;

// May want to consider timings, and invalid valve combinations.

void Outputs::setEvaporatorValve(bool state) {
    // implementation here
}

void Outputs::setEvaporatorBypassValve(bool state) {
    // implementation here
}

void Outputs::setReversingValve(bool state) {
    // implementation here
}

void Outputs::setCompressorSpeed(float percent) {
    int mVolts = (int)(percent/100*COMPRESSOR_MAX_VOLTAGE_MV);
    mod_8AO.setOutputVoltage(1, mVolts);
}

void Outputs::setFanSpeed(float percent) {
    // implementation here
}
