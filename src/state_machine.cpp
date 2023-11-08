#include "state_machine.h"

StateMachine stateMachine;

StateMachine::StateMachine(void)

    : compressorPID(
        compressorPIDinput, // input
        compressorPIDoutput, // output
        compressorPIDsetpoint // setpoint
    )
    {
        tunePID();
}

void StateMachine::tunePID(void){
    compressorPID.SetTunings(otaVars.compressorPID_P, otaVars.compressorPID_I, otaVars.compressorPID_D);
}

void StateMachine::run(void){

    previousState = currentState;
    inputs.pollSensorData();
    inputs.pollPhysicalControls();
    sensorData = inputs.sensorData;
    physicalControls = inputs.physicalControls;

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

    if(*demandSensor > otaVars.demandThreshold + otaVars.demandHysteresis){
        //Demand sensor is above threshold, no heating requested   
        currentState = STANDBY;
        return;
    }

    if(currentState == STANDBY && 
        *demandSensor > otaVars.demandThreshold - otaVars.demandHysteresis){
        //Demand sensor is still above the lower threshold, no heating requested
        //This implements the hysteresis
        return;
        }      

    if(currentState == DEFROST){
        //This means a defrost timer is still running
        defrostState();
        return;
    }

    if(*defrostSensor < otaVars.defrostThreshold){
        //Ambient temperature is below defrost threshold
        currentState = DEFROST;
        defrostState();
        return;
    }

    if(*flexStoreSensor > flexStoreThreshold){
        //Flex store is above threshold
        flexStoreThreshold = otaVars.flexStoreLow;
        currentState = DISCHARGING;
        dischargingState();
        return;
    }
    if(*flexStoreSensor < flexStoreThreshold){
        //Flex store is below threshold
        flexStoreThreshold = otaVars.flexStoreHigh;
        currentState = CHARGING;
        chargingState();
        return;
    }
}

void StateMachine::standbyState(void){
    if (previousState != STANDBY){
        USBSerial.printf("Entering standby mode\n");
        
        USBSerial.printf("Setting fan speed = %f\n", 0);
        outputs.setFanSpeed(otaVars.fanSpeedEnabled);

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

        USBSerial.printf("Setting fan speed = %f\n", otaVars.fanSpeedEnabled);
        outputs.setFanSpeed(otaVars.fanSpeedEnabled);

        compressorManualSpeed(otaVars.compressorSpeedIdle);
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
        
        USBSerial.printf("Setting fan speed = %f\n", otaVars.fanSpeedEnabled);
        outputs.setFanSpeed(otaVars.fanSpeedEnabled);

        compressorManualSpeed(otaVars.compressorSpeedIdle);
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
        
        USBSerial.printf("Setting fan speed = %f\n", otaVars.fanSpeedEnabled);
        outputs.setFanSpeed(otaVars.fanSpeedEnabled);

        compressorManualSpeed(otaVars.compressorSpeedIdle);

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