
#include "outputs.h"

Outputs outputs;

void Outputs::init() {

    vTaskDelay(20 / portTICK_PERIOD_MS);
    mod_8AO.init();
    // Set outputs 1-3 to voltage type, default 0 mV
    for (int i = 1; i <= 3; i++) {
        mod_8AO.setOutputType(i, OutputType::VOLTAGE);
        mod_8AO.setOutputVoltageDefault(i, 0);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
    mod_16RO.init();
    vTaskDelay(20 / portTICK_PERIOD_MS);

}

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
