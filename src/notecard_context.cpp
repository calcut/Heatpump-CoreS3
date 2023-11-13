#include "notecard_context.h"

void myEnvVarCb(const char *key, const char *val, void *userCtx){

    // Assigns received environment variables to the appropriate
    // places. This requires an "unordered_map" of environment variables
    // to be defined in each class that needs to receive them.

    // The incoming type is converted to e.g. float or int as required
    // If the key is not found, it is ignored.

    USBSerial.printf("EnvVar received: key=%s, val=%s\n", key, val);

    try{
        stateMachine.envVars.at(key) = atof(val);
        USBSerial.printf("set stateMachine.envVars[\"%s\"]=%f\n",
                         key, stateMachine.envVars.at(key));
    } catch(std::out_of_range& e){}

    try{
        notecardManager.envVars.at(key) = atoi(val);
        USBSerial.printf("set notecardManager.envVars[\"%s\"]=%d\n",
                         key, notecardManager.envVars.at(key));
    } catch(std::out_of_range& e){}


}
    
void setDefaultEnvironment(void){

    // Copies the current value of the environment variables to the Notecard
    // and saves them as the default values.
    // Typically run once at startup.

    char value[12];
    char* key;
    int floatDecimals = 3;

    for (auto& envVar : notecardManager.envVars) {
        key = const_cast<char*>(envVar.first.c_str());
        dtostrf(envVar.second, 0, 0, value);
        notecardManager.setDefaultEnvironmentVar(key, value);
    }
    for (auto& envVar : stateMachine.envVars) {
        key = const_cast<char*>(envVar.first.c_str());
        dtostrf(envVar.second, 0, floatDecimals, value);
        notecardManager.setDefaultEnvironmentVar(key, value);
    }
}
