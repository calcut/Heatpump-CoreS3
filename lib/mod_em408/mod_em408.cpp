#include "mod_em408.h"


void Mod_em408::init() {
    // Initialization code here
    // You might need to write to or read from some registers
}

void Mod_em408::readVoltage(float *voltage) {
    USBSerial.print("Reading voltage, ");
    // ModbusRTUClient.end();
    // ModbusRTUClient.begin(2400);
    readRegister(EM408_VOLTAGE_HI);
    readRegister(EM408_VOLTAGE_LO);
    // ModbusRTUClient.end();
    // ModbusRTUClient.begin(9600);
    // readRegister(EM408_VOLTAGE_HI);
    // readRegister(EM408_VOLTAGE_LO);
}



void Mod_em408::readRegister(int reg) {
    USBSerial.printf("Reading register %i, ", reg);
    // if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
    if (ModbusRTUClient.requestFrom(slave_id, INPUT_REGISTERS,
                                reg, 1)) {
        USBSerial.print("Success: ");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read());
            USBSerial.print(' ');
        }
        USBSerial.println();
    }
    else {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    }

}

void Mod_em408::writeRegister(int reg, int value) {
    USBSerial.printf("Writing register %i = %i, ", reg, value);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                        reg, 1);
    ModbusRTUClient.write(value);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("Success");
    }
}