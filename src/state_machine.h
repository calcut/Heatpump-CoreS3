#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "outputs.h"
#include "inputs.h"
#include <QuickPID.h>

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
    Inputs::SensorData sensorData;
    Inputs::SensorData sensorDataLimitsMax;
    Inputs::SensorData sensorDataLimitsMin;

    Inputs::PhysicalControls physicalControls;

    float* demandSensor = &sensorData.temperatureData.Tr1_CompressorOut;
    float* defrostSensor = &sensorData.temperatureData.Ta1_EvaporatorIn;
    float* flexStoreSensor = &sensorData.temperatureData.Tw3_FlexStore;

    struct OTAVars{
        float demandThreshold = 0.0;
        float demandHysteresis = 1.0;
        float defrostThreshold = 5.0;
        float flexStoreLow = 20.0;
        float flexStoreHigh = 30.0;
        float compressorSpeedIdle = 20.0; //percent
        float fanSpeedEnabled = 50.0; //percent
        float defrostInterval_s = 60;
    };
    OTAVars otaVars;

    float flexStoreThreshold = 20.0;
    float* compressorPIDinput = &sensorData.temperatureData.Tr1_CompressorOut;
    float* compressorPIDoutput;
    float* compressorPIDsetpoint;

private:

    float defrostTimer = 0.0;

    bool checkLimits(void);
    void standbyState(void);
    void dischargingState(void);
    void chargingState(void);
    void defrostState(void);
    void compressorManualSpeed(float speed_percent);
};

extern StateMachine stateMachine;

#endif // STATE_MACHINE_H
