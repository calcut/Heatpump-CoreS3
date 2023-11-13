#ifndef INPUTS_H
#define INPUTS_H

#include "yotta_module.h"
#include <driver/pcnt.h> //ESP32 Pulse counter
#include <unordered_map>

class Inputs {
public:

    std::unordered_map<std::string, float> temperatureData = {
        {"Tr1_CompressorOut", 0.0},
        {"Tr2_CondenserOut", 0.0},
        {"Tr3_FlexStore", 0.0},
        {"Tr4_Evaporator", 0.0},
        {"Tr5_CompressorIn", 0.0},
        {"Tw1_DHWReturn", 0.0},
        {"Tw2_DHWFlow", 0.0},
        {"Tw3_FlexStore", 0.0},
        {"Tw4_SolarFlow", 0.0},
        {"Tw5_SolarReturn", 0.0},
        {"Ta1_EvaporatorIn", 0.0},
        {"Ta1_EvaporatorOut", 0.0}
    };

    std::unordered_map<std::string, float> pressureData = {
        {"Pr1_CompressorOut", 0.0},
        {"Pr2_Evaporator", 0.0},
        {"Pr3_CompressorIn", 0.0}
    };

    std::unordered_map<std::string, float> flowData = {
        {"Fl1_DHW_lpm", 0.0},
        {"Fl2_Solar", 0.0}
    };

    std::unordered_map<std::string, float> powerData = {
        {"P1_Supply", 0.0},
        {"P2_Compressor", 0.0},
        {"P3_Fan", 0.0}
    };

    std::unordered_map<std::string, float> speedData = {
        {"S1_Compressor", 0.0},
        {"P2_Fan", 0.0}
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
