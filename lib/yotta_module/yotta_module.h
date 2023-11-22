#ifndef YOTTA_MODULE_H
#define YOTTA_MODULE_H

#define MODULE_NAME_ADDR 210

#ifndef YOTTA_MODULE_ADDRESS
#define YOTTA_MODULE_ADDRESS 4
#endif

#include <Arduino.h>
#include <ArduinoModbus.h>


class YottaModule {

    private:
        int slave_id = YOTTA_MODULE_ADDRESS;

    public:
        void readTC_float(float_t *tc);
        void readTC_int(int32_t *tc);
        void readTC_int_decimal(int32_t *tc);
        void setTypeTC();
        void getType();
        void init();
};

#endif