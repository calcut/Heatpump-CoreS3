#include "mod_16ro.h"

void Mod_16RO::getRelays(bool relays[16]) {
       
        int16_t relayreg = 0;
        USBSerial.print("Reading Relay Values: ");

        if (!ModbusRTUClient.requestFrom(id, HOLDING_REGISTERS,
                                    MOD_16RO_OUTPUTS, 1)) {
            USBSerial.print("failed! ");
            USBSerial.println(ModbusRTUClient.lastError());
        }
        else {
            while (ModbusRTUClient.available()) {
                relayreg = ModbusRTUClient.read();
            }

            for (int i = 0; i < 16; i++) {
                relays[i] = bitRead(relayreg, i);
                USBSerial.print(relays[i]);
            }
            USBSerial.println();
        }
}

void Mod_16RO::setRelays(bool relays[16]) {
    

    USBSerial.print("Setting Relay Values: ");

    // Convert bool array to int16_t
    int16_t relayReg = 0;
    for (int i = 0; i < 16; i++) {
        bitWrite(relayReg, i, relays[i]);
        USBSerial.print(relays[i]);
    }

    if(!ModbusRTUClient.holdingRegisterWrite(id, MOD_16RO_OUTPUTS, relayReg)) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    }
    else USBSerial.println("success");   
}

void Mod_16RO::setRelayDefaults(bool relayDefaults[16]) {
    
    USBSerial.print("Setting Relay Defaults: ");

    // Convert bool array to int16_t
    int16_t relayReg = 0;
    for (int i = 0; i < 16; i++) {
        bitWrite(relayReg, i, relayDefaults[i]);
        USBSerial.print(relayDefaults[i]);
    }
    USBSerial.println();

    if(!ModbusRTUClient.holdingRegisterWrite(id, MOD_16RO_OUTPUT_DEFAULTS, relayReg)) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    }
    else USBSerial.println("success");  
}

void Mod_16RO::setWatchdog(int16_t watchdog_ms) {

    if(!ModbusRTUClient.holdingRegisterWrite(id, MOD_16RO_WATCHDOG, watchdog_ms)) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    }
    else USBSerial.println("success");  
}


void Mod_16RO::init(){

    USBSerial.println("\n**** Mod_16RO init ****");

    if (ModbusRTUClient.requestFrom(id, HOLDING_REGISTERS,
                                MOD_16RO_VERSION, 1)) {
        USBSerial.print("Module Detected: ");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read(), HEX);
            USBSerial.print(' ');
        }
        USBSerial.println();
    }

    bool relayDefaults[16] = {false, false, false, false,
                            false, false, false, false,
                            false, false, false, false,
                            false, false, false, false};
    setRelayDefaults(relayDefaults);
    setWatchdog(10000);


}