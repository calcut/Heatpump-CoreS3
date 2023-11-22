#include "relay_module.h"

void RelayModule::getRelays(bool relays[16]) {
       
        int16_t relayreg = 0;
        USBSerial.print("Reading Relay Values: ");

        if (!ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                    RELAY_OUTPUTS, 1)) {
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

void RelayModule::setRelays(bool relays[16]) {
    

    USBSerial.print("Setting Relay Values: ");

    // Convert bool array to int16_t
    int16_t relayreg = 0;
    for (int i = 0; i < 16; i++) {
        bitWrite(relayreg, i, relays[i]);
        USBSerial.print(relays[i]);
    }

    USBSerial.print(' ');

    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         RELAY_OUTPUTS, 1);

    ModbusRTUClient.write(relayreg);

    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
        
}


void RelayModule::init(bool relay_defaults[16]){
    // Read the module name
    USBSerial.println("Reading Relay module name");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                RELAY_VERSION, 1)) {
        USBSerial.print("Module Detected: A-");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read(), HEX);
            USBSerial.print(' ');
        }
        USBSerial.println();
    }

    setWatchdog(10000);
    setRelayDefaults(relay_defaults);

}