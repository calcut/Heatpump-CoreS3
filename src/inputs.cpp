#include "inputs.h"

Inputs inputs;

void Inputs::pollSensorData(void){
    float tc[8];
    float evd_sensors[4];
    yottaModule.readTC_float(tc);
    // Delay seems to be needed to prevent Modbus errors
    // It fails at around 3ms or faster. So setting to 20ms
    vTaskDelay(20 / portTICK_PERIOD_MS);
    evdModule.getSensors(evd_sensors);

    temperatureData["Tr1_CompressorOut"]    = tc[0];
    temperatureData["Tr2_CondenserOut"]     = tc[1];
    temperatureData["Tr3_FlexStore"]        = tc[2];
    temperatureData["Tr4_Evaporator"]       = tc[3];
    temperatureData["Tr5_CompressorIn"]     = tc[4];
    temperatureData["Tw1_DHWReturn"]        = tc[5];
    temperatureData["Tw2_DHWFlow"]          = tc[6];
    temperatureData["Tw3_FlexStore"]        = tc[7];
}

void Inputs::pollPhysicalControls(void){
    physicalControls.handOffAuto = HAND;
    physicalControls.manualState = CHARGING;
    // USBSerial.print("Polling physical controls\n");
}

void Inputs::init(void){
    yottaModule.init();
    vTaskDelay(20 / portTICK_PERIOD_MS);
    evdModule.init();
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