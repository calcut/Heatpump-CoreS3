#ifndef HAL_CORES3_H
#define HAL_CORES3_H

#include <M5Unified.h>
#include "config.h"

#include <FFat.h>
#include <Wire.h>
#include <ArduinoModbus.h>

#ifndef TERMINAL_LOG_LENGTH
#define TERMINAL_LOG_LENGTH 512
#endif

void hal_setup(void);

class SerialDisplay : public HWCDC
//https://stackoverflow.com/questions/60972073/customizing-the-standard-serial-print-functions-in-arduino
{
    using HWCDC::HWCDC; // Inherit constructors
    public:
        size_t write(const uint8_t *buffer, size_t size) override;   // Overriding base functionality
        char logBuffer[TERMINAL_LOG_LENGTH + 1];
};
extern SerialDisplay serialDisplay;

#endif // HAL_CORES3_H
