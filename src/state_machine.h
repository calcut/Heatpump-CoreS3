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

    State currentState;
    State previousState;
    Inputs::SensorData sensorData;
    Inputs::SensorData sensorDataLimitsMax;
    Inputs::SensorData sensorDataLimitsMin;

    Inputs::PhysicalControls physicalControls;

    float* demandSensor = &sensorData.temperatureData.Tr1_CompressorOut;
    float demandThreshold = 0.0;
    float demandHysteresis = 1.0;

    float* defrostSensor = &sensorData.temperatureData.Ta1_EvaporatorIn;
    float defrostThreshold = 5.0;

    float* flexStoreSensor = &sensorData.temperatureData.Tw3_FlexStore;
    float flexStoreThreshold = 20.0;
    float flexStoreLow = 20.0;
    float flexStoreHigh = 30.0;


    float compressorSpeedIdle = 20.0; //percent
    float fanSpeedEnabled = 50.0; //percent



private:
    Inputs inputs;
    Outputs outputs;

    float defrostTimer;
    float defrostInterval;

    float* compressorPIDinput = &sensorData.temperatureData.Tr1_CompressorOut;
    float* compressorPIDoutput;
    float* compressorPIDsetpoint;

    bool checkLimits(void);
    void standbyState(void);
    void dischargingState(void);
    void chargingState(void);
    void defrostState(void);
    void compressorManualSpeed(float speed_percent);
};

extern StateMachine stateMachine;

#endif // STATE_MACHINE_H
