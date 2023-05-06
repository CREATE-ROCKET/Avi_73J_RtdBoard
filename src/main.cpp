#include <Arduino.h>

#include <SPICREATE.h>

#include "infrastructure/router.h"

void loop()
{
    Accel accel;
    accel.AccelX = 1;
    accel.AccelY = 2;
    accel.AccelZ = 3;
    uint8_t addr = 0;
    Router1.accelController->Add(addr, accel);
}
