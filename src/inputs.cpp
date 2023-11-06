#include "inputs.h"

struct Inputs::SensorData Inputs::pollSensorData(void){
    sensorData.temperatureData.Tr1_CompressorOut = 1.0;
    return sensorData;
}

struct Inputs::PhysicalControls Inputs::getPhysicalControls(void){
    physicalControls.handOffAuto = HAND;
    physicalControls.manualState = CHARGING;
    return physicalControls;
}

Inputs::Inputs(void)
    : yottaModule(YOTTA_MODULE_ADDRESS){
    yottaModule.init();
}
