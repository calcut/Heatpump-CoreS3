#include "state_machine.h"

StateMachine stateMachine;

// StateMachine::StateMachine(void)

//     : compressorPID(
//         compressorPIDinput, // input
//         compressorPIDoutput, // output
//         compressorPIDsetpoint // setpoint
//     )
//     {
//         tunePID();
// }

void StateMachine::tunePID(void){
    compressorPID->SetTunings(envVars["compressorPID_P"],
                             envVars["compressorPID_I"],
                             envVars["compressorPID_D"]);
}

void StateMachine::init(void){
    USBSerial.println("Init state machine");

    inputs.init();
    vTaskDelay(20 / portTICK_PERIOD_MS);
    outputs.init();

    demandSensor = &inputs.temperatureData["Tw2_DHWFlow"];
    defrostSensor = &inputs.temperatureData["Ta1_EvaporatorIn"];
    flexStoreSensor = &inputs.temperatureData["Tw3_FlexStore"];
    compressorPIDinput = &inputs.temperatureData["Tw2_DHWFlow"];
    compressorPIDsetpoint = &envVars["demandThreshold"];

    Setpoint = 100;
    Input = 0.0;

    compressorPID = new QuickPID(
        compressorPIDinput,
        &compressorPIDoutput,
        compressorPIDsetpoint,
        // compressorPIDinput, // input
        // compressorPIDoutput, // output
        // compressorPIDsetpoint, // setpoint
        envVars["compressorPID_P"],
        envVars["compressorPID_I"],
        envVars["compressorPID_D"],
        QuickPID::Action::direct
    );
    compressorPID->SetMode(QuickPID::Control::automatic);
}

void StateMachine::run(void){

    USBSerial.println("Running state machine");
    previousState = currentState;
    inputs.pollSensorData();
    inputs.pollPhysicalControls();
    stateMachine.compressorPID->Compute();


    if(checkLimits() == false){
        // Add logging or error handling
        enabled = false;
        currentState = ERROR;
        return;
    }

    if(inputs.physicalControls.handOffAuto == Inputs::HandOffAuto::OFF){
        USBSerial.println("SM: Hand off auto switch is in OFF mode");
        currentState = STANDBY;
        return;
    }

    if(inputs.physicalControls.handOffAuto == Inputs::HandOffAuto::HAND){

        USBSerial.println("SM: HAND mode");
        if(inputs.physicalControls.manualState == Inputs::ManualState::CHARGING){
            currentState = CHARGING;
            USBSerial.println("SM: Manual CHARGING");
            chargingState();
        }
        else if(inputs.physicalControls.manualState == Inputs::ManualState::DISCHARGING){
            currentState = DISCHARGING;
            USBSerial.println("SM: Manual DISCHARGING");
            dischargingState();
        }
        else if(inputs.physicalControls.manualState == Inputs::ManualState::DEFROST){
            currentState = DEFROST;
            USBSerial.println("SM: Manual DEFROST");
            defrostState();
        }
        else{
            USBSerial.println("SM: Error, Invalid manual state, setting to standby");
            currentState = STANDBY;
            standbyState();
        }
        return;
    }

    if(enabled == false){
        USBSerial.println("SM: Auto Mode, but disabled");
        if(currentState != ERROR){
            currentState = STANDBY;
        }
        return;
    }

    if(*demandSensor > envVars["demandThreshold"] + envVars["demandHysteresis"]){
        //Demand sensor is above threshold, no heating requested   
        currentState = STANDBY;
        USBSerial.println("SM: STANDBY (demand sensor above upper threshold)");
        return;
    }

    if(currentState == STANDBY && 
        *demandSensor > envVars["demandThreshold"] - envVars["demandHysteresis"]){
        //Demand sensor is still above the lower threshold, no heating requested
        //This implements the hysteresis
        USBSerial.println("SM: STANDBY (demand sensor above lower threshold)");
        return;
        }      

    if(currentState == DEFROST){
        //This means a defrost timer is still running
        USBSerial.println("SM: DEFROST");
        defrostState();
        return;
    }

    if(*defrostSensor < envVars["defrostThreshold"]){
        //Ambient temperature is below defrost threshold
        currentState = DEFROST;
        USBSerial.println("SM: DEFROST");
        defrostState();
        return;
    }

    if(*flexStoreSensor > flexStoreThreshold){
        //Flex store is above threshold
        flexStoreThreshold = envVars["flexStoreLow"];
        currentState = DISCHARGING;
        USBSerial.println("SM: DISCHARGING");
        dischargingState();
        return;
    }
    if(*flexStoreSensor < flexStoreThreshold){
        //Flex store is below threshold
        flexStoreThreshold = envVars["flexStoreHigh"];
        currentState = CHARGING;
        USBSerial.println("SM: CHARGING");
        chargingState();
        return;
    }
}

void StateMachine::standbyState(void){
    if (previousState != STANDBY){
        USBSerial.printf("Entering standby mode\n");
        
        USBSerial.printf("Setting fan speed = %f\n", 0);
        outputs.setFanSpeed(envVars["fanSpeedEnabled"]);

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

        USBSerial.printf("Setting fan speed = %f\n", envVars["fanSpeedEnabled"]);
        outputs.setFanSpeed(envVars["fanSpeedEnabled"]);

        compressorManualSpeed(envVars["compressorSpeedIdle"]);
        outputs.setEvaporatorValve(outputs.CLOSED);
        outputs.setEvaporatorBypassValve(outputs.OPEN);
        outputs.setReversingValve(outputs.REVERSE);
        vTaskDelay(VALVE_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

        compressorPID->SetMode(QuickPID::Control::automatic);
        USBSerial.println("In discharging state");        
    }
    outputs.setCompressorSpeed(compressorPIDoutput);
}

void StateMachine::chargingState(void){
    if (previousState != CHARGING){
        USBSerial.printf("Entering charging state");
        
        USBSerial.printf("Setting fan speed = %f\n", envVars["fanSpeedEnabled"]);
        outputs.setFanSpeed(envVars["fanSpeedEnabled"]);

        compressorManualSpeed(envVars["compressorSpeedIdle"]);
        outputs.setEvaporatorValve(outputs.OPEN);
        outputs.setEvaporatorBypassValve(outputs.CLOSED);
        outputs.setReversingValve(outputs.FORWARD);
        vTaskDelay(VALVE_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

        // compressorPID->SetMode(QuickPID::Control::automatic);
        USBSerial.println("In charging state");        
    }
    // USBSerial.printf("Compressor PID output = %f\n", *compressorPIDoutput);
    // outputs.setCompressorSpeed(compressorPIDoutput);

}

void StateMachine::defrostState(void){
    if (previousState != DEFROST){
        USBSerial.println("Entering defrost state");
        
        USBSerial.printf("Setting fan speed = %f\n", envVars["fanSpeedEnabled"]);
        outputs.setFanSpeed(envVars["fanSpeedEnabled"]);

        compressorManualSpeed(envVars["compressorSpeedIdle"]);

        outputs.setEvaporatorValve(outputs.OPEN);
        outputs.setEvaporatorBypassValve(outputs.CLOSED);
        outputs.setReversingValve(outputs.FORWARD);

        // compressorPID->SetMode(QuickPID::Control::automatic);
        USBSerial.println("In defrost state");

        // Start defrost Timer here
    }
    outputs.setCompressorSpeed(compressorPIDoutput);

}

bool StateMachine::checkLimits(){
    // Check if the compressor speed is within limits etc
    return true;
}

void StateMachine::compressorManualSpeed(float speed_percent){

    USBSerial.printf("Setting compressor to manual speed=%f\n", speed_percent);
    compressorPID->SetMode(QuickPID::Control::manual);
    outputs.setCompressorSpeed(speed_percent);
    vTaskDelay(COMPRESSOR_TRANSITION_TIME_MS / portTICK_PERIOD_MS);

    USBSerial.println("...done");

};