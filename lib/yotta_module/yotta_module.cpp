#include "yotta_module.h"


YottaModule::YottaModule(int slave_id) {
    slave_id = slave_id;
    // ModbusRTUClient.master();
    // ModbusRTUClient.slave(slave_id);
}
void YottaModule::readTC_float(float_t tc[8]) {

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                736, 16)) {  //ABCD

        for (int i = 0; i < 8; i++) {
            byte byte_array[4];
            uint16_t msbs = ModbusRTUClient.read();
            uint16_t lsbs = ModbusRTUClient.read();

            // Put bytes in the correct order
            memcpy(&byte_array[2], &msbs, 2);
            memcpy(&byte_array[0], &lsbs, 2);

            // Convert to float and print
            memcpy(&tc[i], &byte_array, 4);
            // USBSerial.printf("TC[%i]: ", i);
            // USBSerial.println(tc[i]);
        }
    }
}
void YottaModule::readTC_int(int32_t tc[8]) {

        if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                    96, 8)) {
            USBSerial.print("Input Values integer: ");
            while (ModbusRTUClient.available()) {
                int16_t temperature = ModbusRTUClient.read();
                USBSerial.print(temperature, DEC);
                USBSerial.print(' ');
            }
            USBSerial.println();
        }
}

void YottaModule::readTC_int_decimal(int32_t tc[8]) {

        if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                128, 8)) {
            USBSerial.print("Input Values integer_decimal" );
            while (ModbusRTUClient.available()) {
                int16_t temperature = ModbusRTUClient.read();
                USBSerial.print(temperature, DEC);
                USBSerial.print(' ');
            }
            USBSerial.println();
        }
}



void YottaModule::setTypeTC(){

    // Set the input types to K type thermocouple
    USBSerial.println("Setting input types to K type thermocouple");

    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS, 64, 8);
    for (int i = 0; i < 8; i++) {
        ModbusRTUClient.write(0x0003);
    }
    ModbusRTUClient.endTransmission();
}

void YottaModule::getType(){
    // Read the input types
    USBSerial.println("Reading input types");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                64, 8)) {
        USBSerial.print("Input types: 0x ");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read(), HEX);
            USBSerial.print(' ');
        }
        USBSerial.println();
    }
}

void YottaModule::init(){
    // Read the module name
    ModbusRTUClient.begin(9600, SERIAL_8N1);

    USBSerial.println("Reading module name");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                MODULE_NAME_ADDR, 1)) {
        USBSerial.print("Module Detected: A-");
        while (ModbusRTUClient.available()) {
            USBSerial.print(ModbusRTUClient.read(), HEX);
            USBSerial.print(' ');
        }
        USBSerial.println();
    }

    setTypeTC();
    getType();
}