#include "hal_coreS3.h"

RS485Class RS485(Serial2, PIN_RX_RS485, PIN_TX_RS485, PIN_DE_RS485, -1);

void hal_setup(void){
    USBSerial.begin();
    M5.begin();
    M5.Display.setBrightness(60);

    ModbusRTUClient.begin(9600, SERIAL_8N1);

    //Default is just boost enabled (so can start from battery), AKA POWER_MODE_USB_IN_BUS_IN
    M5.In_I2C.bitOff(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN = 1

    M5.In_I2C.bitOff(AW9523_ADDR, 0x02, 0b00000010, 100000L);  // BUS_OUT_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x02, 0b00000010, 100000L);  // BUS_OUT_EN = 1

    M5.In_I2C.bitOff(AW9523_ADDR, 0x02, 0b00100000, 100000L);  // USB_OTG_EN = 0
    // M5.In_I2C.bitOn(AW9523_ADDR, 0x02, 0b00100000, 100000L);  // USB_OTG_EN = 1

    Wire.begin(PIN_SDA_I2C_EXT, PIN_SCL_I2C_EXT, 400000);  //Init I2C_EXT

};


size_t SerialDisplay::write(const uint8_t *buffer, size_t size){

    // This intercepts SerialDisplay.print() and similar.
    // It captures the text and appends it to the end of a log buffer for display on the screen

    char *txt_in = (char*)buffer;
    uint16_t txt_len = strlen(txt_in);
    uint16_t old_len = strlen(logBuffer); 

    //Append the new text to the end of the log, deleting the oldest text if necessary
    if (old_len + txt_len > TERMINAL_LOG_LENGTH){
        //If the new text is longer than the log, then delete the oldest text
        uint16_t new_start = old_len - (TERMINAL_LOG_LENGTH - txt_len);
        uint16_t new_len = old_len - new_start;
        memcpy(logBuffer, &logBuffer[new_start], new_len);
        memcpy(&logBuffer[new_len], txt_in, txt_len);

        logBuffer[new_len+txt_len] = '\0';
    }
    else{
        //If the new text is shorter than the log, then append it to the end
        memcpy(&logBuffer[old_len], txt_in, txt_len);
        logBuffer[old_len + txt_len] = '\0';
    }

    return HWCDC::write(buffer, size);
}
SerialDisplay serialDisplay;