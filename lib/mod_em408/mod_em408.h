#ifndef MOD_EM408_H
#define MOD_EM408_H

#ifndef MOD_EM408_ADDRESS
#define MOD_EM408_ADDRESS 1
#endif

#include <ArduinoModbus.h>

#define EM408_TOTAL_ACTIVE_ENERGY_HI 0
#define EM408_TOTAL_ACTIVE_ENERGY_LO 1
#define EM408_IMPORT_ACTIVE_ENERGY_HI 2
#define EM408_IMPORT_ACTIVE_ENERGY_LO 3
#define EM408_EXPORT_ACTIVE_ENERGY_HI 4
#define EM408_EXPORT_ACTIVE_ENERGY_LO 5
#define EM408_VOLTAGE_HI 6
#define EM408_VOLTAGE_LO 7



class Mod_em408 {

private:
    int slave_id = MOD_EM408_ADDRESS;

public:
    void init();
    void readVoltage(float *voltage);
    void readRegister(int reg);
    void writeRegister(int reg, int value);
};

#endif