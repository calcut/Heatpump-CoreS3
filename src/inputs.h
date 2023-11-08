#ifndef INPUTS_H
#define INPUTS_H

#include "yotta_module.h"
#include <driver/pcnt.h> //ESP32 Pulse counter

class Inputs {
public:

    struct TemperatureData {
        float Tr1_CompressorOut;
        float Tr2_CondenserOut;
        float Tr3_FlexStore;
        float Tr4_Evaporator;
        float Tr5_CompressorIn;
        float Tw1_DHWReturn;
        float Tw2_DHWFlow;
        float Tw3_FlexStore;
        float Tw4_SolarFlow;
        float Tw5_SolarReturn;
        float Ta1_EvaporatorIn;
        float Ta1_EvaporatorOut;
    };

    struct PressureData {
        float Pr1_CompressorOut;
        float Pr2_Evaporator;
        float Pr3_CompressorIn;
    };

    struct FlowData {
        float Fl1_DHW_lpm;
        float Fl2_Solar;
    };

    struct PowerData {
        float P1_Supply;
        float P2_Compressor;
        float P3_Fan;
    };

    struct SpeedData {
        float S1_Compressor;
        float P2_Fan;
    };

    struct SensorData {
        TemperatureData temperatureData;
        PressureData pressureData;
        FlowData flowData;
        PowerData powerData;
        SpeedData speedData;
    };

    enum HandOffAuto {
        HAND,
        OFF,
        AUTO,
    };

    enum ManualState {
        CHARGING,
        DISCHARGING,
        DEFROST,
    };

    struct PhysicalControls{
        HandOffAuto handOffAuto;
        ManualState manualState;
    };

    Inputs(void);
    void initFlowMeters(int pin);
    void serviceFlowMeters(void);
    void pollSensorData(void);
    void pollPhysicalControls(void);
    SensorData sensorData;
    PhysicalControls physicalControls;

private:
    YottaModule yottaModule;

    int previousPulseCount = 0;
    int previousPulseTime = 0;
    int16_t counterVal;
    int flowPPS;
};
extern Inputs inputs;

#endif // INPUTS_H
