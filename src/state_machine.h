#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "outputs.h"
#include "inputs.h"
#include <QuickPID.h>
#include <unordered_map>


class StateMachine {
public:

    enum State {
        STANDBY,
        CHARGING,
        DISCHARGING, 
        DEFROST,
        ERROR
    };

    StateMachine();
    void run();
    bool enabled = false;

    QuickPID compressorPID;
    Inputs inputs;
    Outputs outputs;

    State currentState;
    State previousState;
    // Inputs::SensorData sensorData;
    // Inputs::SensorData sensorDataLimitsMax;
    // Inputs::SensorData sensorDataLimitsMin;

    Inputs::PhysicalControls physicalControls;

    float* demandSensor = &inputs.temperatureData["Tw2_DHWFlow"];
    float* defrostSensor = &inputs.temperatureData["Ta1_EvaporatorIn"];
    float* flexStoreSensor = &inputs.temperatureData["Tw3_FlexStore"];

    std::unordered_map<std::string, float> envVars = {
        {"demandThreshold", 0.0},
        {"demandHysteresis", 1.0},
        {"defrostThreshold", 5.0},
        {"flexStoreLow", 20.0},
        {"flexStoreHigh", 30.0},
        {"compressorSpeedIdle", 20.0},
        {"fanSpeedEnabled", 50.0},
        {"defrostInterval_s", 60},
        {"compressorPID_P", 0.1},
        {"compressorPID_I", 0.0},
        {"compressorPID_D", 0.0}
    };

    float flexStoreThreshold = 20.0;
    float* compressorPIDinput = &inputs.temperatureData["Tw2_DHWFlow"];
    float* compressorPIDsetpoint = &envVars["demandThreshold"];
    float* compressorPIDoutput;



private:

    float defrostTimer = 0.0;

    bool checkLimits(void);
    void standbyState(void);
    void dischargingState(void);
    void chargingState(void);
    void defrostState(void);
    void tunePID(void);
    void compressorManualSpeed(float speed_percent);
};

extern StateMachine stateMachine;

#endif // STATE_MACHINE_H
