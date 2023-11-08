#include <Notecard.h>
#include "NotecardEnvVarManager.h"

#include "state_machine.h"

struct envVars{
    StateMachine::OTAVars *otaVars = &stateMachine.otaVars;
    
    // Inputs::SensorData *sensorDataLimitsMin = &stateMachine.sensorDataLimitsMin;
    // Inputs::SensorData *sensorDataLimitsMax = &stateMachine.sensorDataLimitsMax;
};

struct qoVars{
    Inputs::SensorData *sensorData = &stateMachine.sensorData;
    StateMachine::State *state = &stateMachine.currentState;

};

struct dbVars{

};