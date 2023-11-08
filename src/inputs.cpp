#include "inputs.h"

Inputs inputs;

struct Inputs::SensorData Inputs::getSensorData(void){
    sensorData.temperatureData.Tr1_CompressorOut = 1.0;
    return sensorData;
}

void Inputs::pollSensorData(void){
    sensorData.temperatureData.Tr1_CompressorOut = 1.0;
    USBSerial.print("Polling sensor data\n");
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

void Inputs::serviceFlowMeters(void){

    pcnt_get_counter_value(PCNT_UNIT_0, &counterVal);

    if (millis() - previousPulseTime != 0){
        flowPPS = ((counterVal - previousPulseCount)*1000)/(millis() - previousPulseTime);
        sensorData.flowData.Fl1_DHW_lpm = flowPPS * 60 / 4600; //4600 pulses per litre
    }

    previousPulseCount = counterVal;
    previousPulseTime = millis();
    
}

void Inputs::initFlowMeters(void){
    pcnt_config_t pcntCh1 = {
        .pulse_gpio_num = PIN_PULSE_COUNT,
        .ctrl_gpio_num = PCNT_PIN_NOT_USED,
        .lctrl_mode = PCNT_MODE_KEEP,
        .hctrl_mode = PCNT_MODE_KEEP,
        .pos_mode = PCNT_COUNT_DIS,
        .neg_mode = PCNT_COUNT_INC,
        .counter_h_lim = 32767,
        .counter_l_lim = -32768,
        .unit = PCNT_UNIT_0,
        .channel = PCNT_CHANNEL_0,
    };
    pcnt_unit_config(&pcntCh1);
    pcnt_counter_clear(PCNT_UNIT_0);
    USBSerial.printf("Flow meter initialised on pin %d\n", PIN_PULSE_COUNT);
}