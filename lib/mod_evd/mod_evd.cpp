#include "mod_evd.h"

void Mod_evd::getSensors(float sensors[4]) {
       
    USBSerial.println("Reading Evd Values: ");
    int16_t value;

    if (!ModbusRTUClient.requestFrom(id, HOLDING_REGISTERS,
                                EVD_S1_READ, 4)) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    }
    else {
        for (int i = 0; i < 4; i++) {
            value = ModbusRTUClient.read();
            sensors[i] = (float)value / 10;
            USBSerial.printf("S%i: %0.2f\n", i+1, sensors[i]);
        }
    }
}


void Mod_evd::init(){

    USBSerial.println("\n**** Mod_evd init ****");

    USBSerial.println("Reading Evd Network settings");
    if (ModbusRTUClient.requestFrom(id, HOLDING_REGISTERS,
                                EVD_NETWORK_SETTINGS, 1)) {
        USBSerial.print("Setting Detected: ");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read());
            USBSerial.print(' ');
        }
        USBSerial.println();
    }
    else {
        USBSerial.print("failed! is module connected? baud rate correct? ");
        USBSerial.println(ModbusRTUClient.lastError());
        updateNetworkSettings();
    }
    // Set Probe S1 Type to "6" (0-5V, 0-34.5 barg)
    writeRegister(EVD_S1_CONFIG, 6);
    // Set Probe S2 Type to "1" (Carel NTC)
    writeRegister(EVD_S2_CONFIG, 1);
    // Set Probe S3 Type to "6" (0-5V, 0-34.5 barg)
    writeRegister(EVD_S3_CONFIG, 6);
    // Set Probe S4 Type to "1" (Carel NTC)
    writeRegister(EVD_S4_CONFIG, 1);


}

void Mod_evd::writeRegister(int reg, int value){
    USBSerial.printf("Writing register %i = %i, ", reg, value);
    ModbusRTUClient.beginTransmission(id, HOLDING_REGISTERS,
                                        reg, 1);
    ModbusRTUClient.write(value);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("Success");
    }
}


void Mod_evd::updateNetworkSettings(){

    USBSerial.println("Switching to EvD default Baud rate 19200, SERIAL_8N2");

    ModbusRTUClient.end();
    ModbusRTUClient.begin(19200, SERIAL_8N2); // Default for EvD

            // Change to Network Setting 5 = 9600 baud, 1 stop, no parity
    USBSerial.println("Setting EvD Network Settings");
    ModbusRTUClient.beginTransmission(id, HOLDING_REGISTERS,
                                        EVD_NETWORK_SETTINGS, 1);
    ModbusRTUClient.write(5);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("Success, changed to 9600 baud, SERIAL_8N1");
    }

    ModbusRTUClient.end();
    ModbusRTUClient.begin(RS485_BAUD, SERIAL_8N1);
}

void Mod_evd::resetNetworkSettings(){
    // This is just intended for debug/testing

    USBSerial.println("Resetting EvD Network Settings");
    ModbusRTUClient.beginTransmission(id, HOLDING_REGISTERS,
                                        EVD_NETWORK_SETTINGS, 1);
    ModbusRTUClient.write(2); // This is the default
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("Success, changed to 19200 baud, SERIAL_8N2");
    }
}