#include "notecard_context.h"

// EnvVars envVars;

void myEnvVarCb(const char *key, const char *val, void *userCtx)
{
    // Cast the userCtx to the appropriate type.
    // EnvVars &ev = *(EnvVars *)userCtx;

    USBSerial.print("\nCallback received variable \"");
    USBSerial.print(key);
    USBSerial.print("\" with value \"");
    USBSerial.print(val);
    USBSerial.println(".");


    try{
        stateMachine.envVars.at(key) = atof(val);
        USBSerial.printf("set stateMachine.envVars[\"%s\"]=%f\n", key, stateMachine.envVars.at(key));
    } catch(std::out_of_range& e){}

    try{
        notecardManager.envVars.at(key) = atoi(val);
        USBSerial.printf("%s: %d\n", key, notecardManager.envVars.at(key));
    } catch(std::out_of_range& e){}


}
    
void setDefaultEnvironment(void){

    char* value;
    char* key;
    int decimals = 3;

    for (auto& envVar : notecardManager.envVars) {
        key = const_cast<char*>(envVar.first.c_str());
        dtostrf(envVar.second, 0, decimals, value);
        notecardManager.setDefaultEnvironmentVar(key, value);
    }
    // for (auto& envVar : stateMachine.envVars) {
    //     // key = const_cast<char*>(envVar.first.c_str());
    //     // dtostrf(envVar.second, 0, decimals, value);
    //     key = "def";
    //     value = "456";
    //     notecardManager.setDefaultEnvironmentVar(key, value);
    // }
}
