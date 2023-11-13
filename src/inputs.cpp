#include "inputs.h"

Inputs inputs;

void Inputs::pollSensorData(void){
    temperatureData["Tr1_CompressorOut"] = 1.0;
    // USBSerial.print("Polling sensor data\n");
}

void Inputs::pollPhysicalControls(void){
    physicalControls.handOffAuto = HAND;
    physicalControls.manualState = CHARGING;
    // USBSerial.print("Polling physical controls\n");
}

    Inputs::Inputs(void)
    : yottaModule(YOTTA_MODULE_ADDRESS){
    yottaModule.init();
}

void Inputs::serviceFlowMeters(void){

    pcnt_get_counter_value(PCNT_UNIT_0, &counterVal);

    if (millis() - previousPulseTime != 0){
        flowPPS = ((counterVal - previousPulseCount)*1000)/(millis() - previousPulseTime);
        inputs.flowData["Fl1_DHW_lpm"] = flowPPS * 60 / 4600; //4600 pulses per litre
    }

    previousPulseCount = counterVal;
    previousPulseTime = millis();
    
}

void Inputs::initFlowMeters(int pin){
    pcnt_config_t pcntCh1 = {
        .pulse_gpio_num = pin,
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
    USBSerial.printf("Flow meter initialised on pin %d\n", pin);
}