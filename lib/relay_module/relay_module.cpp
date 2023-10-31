#include "relay_module.h"


RelayModule::RelayModule(int slave_id) {
    slave_id = slave_id;
    // ModbusRTUClient.master();
    // ModbusRTUClient.slave(slave_id);
}

void RelayModule::getRelays(bool relays[16]) {

        if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                    OUTPUTS_ADDR, 1)) {
            USBSerial.print("Relay Values: ");
            while (ModbusRTUClient.available()) {
                int16_t relayreg = ModbusRTUClient.read();
                for (int i = 0; i < 16; i++) {
                    relays[i] = bitRead(relayreg, i);
                }
                USBSerial.print(relayreg, BIN);
                USBSerial.print(' ');
            }
            USBSerial.println();

        }
}


void RelayModule::init(bool relay_defaults[16]){
    // Read the module name
    USBSerial.println("Reading Relay module name");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                MODULE_NAME_ADDR, 1)) {
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