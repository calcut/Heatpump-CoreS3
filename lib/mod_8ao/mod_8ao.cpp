#include "mod_8ao.h"

void Mod_8AO::setOutputVoltage(int output, int mVolts) {

    // check if output is set to voltage type
    if (output_types[output - 1] != VOLTAGE) {
        USBSerial.printf("Output %i is not set to voltage type", output);
        return;
    }

    USBSerial.printf("Setting output %i to %i mVolts", output, mVolts);
    int reg = MOD_8AO_OUTPUT1 + (output - 1);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         reg, 1);
    ModbusRTUClient.write(mVolts);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}

void Mod_8AO::setOutputVoltageDefault(int output, int mVolts) {

    // check if output is set to voltage type
    if (output_types[output - 1] != VOLTAGE) {
        USBSerial.printf("Output %i is not set to voltage type", output);
        return;
    }

    USBSerial.printf("Setting output %i Default to %i mVolts", output, mVolts);
    int reg = MOD_8AO_DEFAULT_OUTPUT1 + (output - 1);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         reg, 1);
    ModbusRTUClient.write(mVolts);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}

void Mod_8AO::setOutputCurrent(int output, int uAmps) {

    // check if output is set to current type
    if (output_types[output - 1] != CURRENT_0_20MA) {
        USBSerial.printf("Output %i is not set to current type", output);
        return;
    }

    USBSerial.printf("Setting output %i to %i uAmps", output, uAmps);
    int reg = MOD_8AO_OUTPUT1 + (output - 1);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         reg, 1);
    ModbusRTUClient.write(uAmps);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}

void Mod_8AO::setOutputCurrentDefault(int output, int uAmps) {

    // check if output is set to current type
    if (output_types[output - 1] != CURRENT_0_20MA) {
        USBSerial.printf("Output %i is not set to current type", output);
        return;
    }

    USBSerial.printf("Setting output %i Default to %i uAmps", output, uAmps);
    int reg = MOD_8AO_DEFAULT_OUTPUT1 + (output - 1);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         reg, 1);
    ModbusRTUClient.write(uAmps);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}

void Mod_8AO::setOutputType(int output, int type) {
    // output_types[output - 1] = type;
    USBSerial.printf("Setting output %i to type %i", output, type);
    int reg = MOD_8AO_OUTPUT_TYPE1 + (output - 1);
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         reg, 1);
    ModbusRTUClient.write(type);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}

void Mod_8AO::setWatchdog(int16_t watchdog_ms) {
    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS,
                                         MOD_8AO_WATCHDOG, 1);
    ModbusRTUClient.write(watchdog_ms);
    if (!ModbusRTUClient.endTransmission()) {
        USBSerial.print("failed! ");
        USBSerial.println(ModbusRTUClient.lastError());
    } else {
        USBSerial.println("success");
    }
}