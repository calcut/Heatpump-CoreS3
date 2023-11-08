#include "state_machine.h"

StateMachine stateMachine;

StateMachine::StateMachine(void)

    : compressorPID(
        compressorPIDinput, // input
        compressorPIDoutput, // output
        compressorPIDsetpoint // setpoint
    )
    {
    defrostTimer = 0.0;
    defrostInterval = 60.0;
}

void StateMachine::run(void){

    previousState = currentState;
    inputs.pollSensorData();
    sensorData = inputs.getSensorData();
    physicalControls = inputs.getPhysicalControls();

    if(enabled == false){
        if(currentState != ERROR){
            currentState = STANDBY;
        }
        return;
    }

    if(checkLimits() == false){
        // Add logging or error handling
        enabled = false;
        currentState = ERROR;
        return;
    }

    if(*demandSensor > demandThreshold + demandHysteresis){
        //Demand sensor is above threshold, no heating requested   
        currentState = STANDBY;
        return;
    }

    if(currentState == STANDBY && 
        *demandSensor > demandThreshold - demandHysteresis){
        //Demand sensor is still above the lower threshold, no heating requested
        //This implements the hysteresis
        return;
        }      

    if(currentState == DEFROST){
        //This means a defrost timer is still running
        defrostState();
        return;
    }

    if(*defrostSensor < defrostThreshold){
        //Ambient temperature is below defrost threshold
        currentState = DEFROST;
        defrostState();
        return;
    }

    if(*flexStoreSensor > flexStoreThreshold){
        //Flex store is above threshold
        flexStoreThreshold = flexStoreLow;
        currentState = DISCHARGING;
        dischargingState();
        return;
    }
    if(*flexStoreSensor < flexStoreThreshold){
        //Flex store is below threshold
        flexStoreThreshold = flexStoreHigh;
        currentState = CHARGING;
        chargingState();
        return;
    }
}

void StateMachine::standbyState(void){
    if (previousState != STANDBY){
        USBSerial.printf("Entering standby mode\n");
        
        USBSerial.printf("Setting fan speed = %f\n", 0);
        outputs.setFanSpeed(fanSpeedEnabled);

        compressorManualSpeed(0);
        outputs.setEvaporatorValve(outputs.OPEN);
        outputs.setEvaporatorBypassValve(outputs.CLOSED);
        outputs.setReversingValve(outputs.FORWARD);
        vTaskDelay(VALVE_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

        USBSerial.println("In standby state");        
    }
    outputs.setCompressorSpeed(0);

}

void StateMachine::dischargingState(void){
    if (previousState != DISCHARGING){
        USBSerial.printf("Entering discharging mode\n");

        USBSerial.printf("Setting fan speed = %f\n", fanSpeedEnabled);
        outputs.setFanSpeed(fanSpeedEnabled);

        compressorManualSpeed(compressorSpeedIdle);
        outputs.setEvaporatorValve(outputs.CLOSED);
        outputs.setEvaporatorBypassValve(outputs.OPEN);
        outputs.setReversingValve(outputs.REVERSE);
        vTaskDelay(VALVE_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

        compressorPID.SetMode(QuickPID::Control::automatic);
        USBSerial.println("In discharging state");        
    }
    outputs.setCompressorSpeed(*compressorPIDoutput);
}

void StateMachine::chargingState(void){
    if (previousState != CHARGING){
        USBSerial.printf("Entering charging state");
        
        USBSerial.printf("Setting fan speed = %f\n", fanSpeedEnabled);
        outputs.setFanSpeed(fanSpeedEnabled);

        compressorManualSpeed(compressorSpeedIdle);
        outputs.setEvaporatorValve(outputs.OPEN);
        outputs.setEvaporatorBypassValve(outputs.CLOSED);
        outputs.setReversingValve(outputs.FORWARD);
        vTaskDelay(VALVE_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

        compressorPID.SetMode(QuickPID::Control::automatic);
        USBSerial.println("In charging state");        
    }
    outputs.setCompressorSpeed(*compressorPIDoutput);

}

void StateMachine::defrostState(void){
    if (previousState != DEFROST){
        USBSerial.println("Entering defrost state");
        
        USBSerial.printf("Setting fan speed = %f\n", fanSpeedEnabled);
        outputs.setFanSpeed(fanSpeedEnabled);

        compressorManualSpeed(compressorSpeedIdle);

        outputs.setEvaporatorValve(outputs.OPEN);
        outputs.setEvaporatorBypassValve(outputs.CLOSED);
        outputs.setReversingValve(outputs.FORWARD);

        compressorPID.SetMode(QuickPID::Control::automatic);
        USBSerial.println("In defrost state");

        // Start defrost Timer here
    }
    outputs.setCompressorSpeed(*compressorPIDoutput);

}

bool StateMachine::checkLimits(){
    // Check if the compressor speed is within limits etc
    return true;
}

void StateMachine::compressorManualSpeed(float speed_percent){

    USBSerial.printf("Setting compressor to manual speed=%f\n", speed_percent);
    compressorPID.SetMode(QuickPID::Control::manual);
    outputs.setCompressorSpeed(speed_percent);
    vTaskDelay(COMPRESSOR_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

    USBSerial.println("...done");

};