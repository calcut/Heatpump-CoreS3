#include "notecard_manager.h"
#include "state_machine.h"

struct EnvVars{
    StateMachine::OTAVars *stateMachineVars = &stateMachine.otaVars;
    int *serviceInterval_s = &notecardManager.serviceInterval_s;
    int *timeSyncInterval_s = &notecardManager.timeSyncInterval_s;
    // Inputs::SensorData *sensorDataLimitsMin = &stateMachine.sensorDataLimitsMin;
    // Inputs::SensorData *sensorDataLimitsMax = &stateMachine.sensorDataLimitsMax;
};

struct QoVars{
    Inputs::SensorData *sensorData = &stateMachine.sensorData;
    Inputs::PhysicalControls *physicalControls = &stateMachine.physicalControls;
    StateMachine::State *state = &stateMachine.currentState;

};

extern EnvVars envVars;

// struct dbVars{

// };


    // if (NotecardEnvVarManager_setEnvVarCb(envVarManager, envVarManagerCb, &envVarCache) != NEVM_SUCCESS)
    // {
    // USBSerial.println("Failed to set callback for NotecardEnvVarManager.");
    // }

void myEnvVarCb(const char *var, const char *val, void *userCtx);
