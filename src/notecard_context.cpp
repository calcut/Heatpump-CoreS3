#include "notecard_context.h"

EnvVars envVars;

void myEnvVarCb(const char *var, const char *val, void *userCtx)
{
    // Cast the userCtx to the appropriate type.
    EnvVars &ev = *(EnvVars *)userCtx;

    USBSerial.print("\nCallback received variable \"");
    USBSerial.print(var);
    USBSerial.print("\" with value \"");
    USBSerial.print(val);
    USBSerial.print("\" and context 0x");
    USBSerial.print((unsigned long)userCtx, HEX);
    USBSerial.println(".");


    // if (strcmp(var, "_sn") == 0) {
    //     strlcpy(cache->serial_number, val, sizeof(cache->serial_number));
    // }
    // else if (strcmp(var, "string_a") == 0) {
    //     strlcpy(cache->string_a, val, sizeof(cache->string_a));
    // }
    // else if (strcmp(var, "mode") == 0) {
    //     cache->mode = atoi(val);
    // }

    // Consider changing to std::unordered_map with string keys and the appropriate value type
    if (strcmp(var, "demandThreshold") == 0) {
        ev.stateMachineVars->demandThreshold = atof(val);
    };
}