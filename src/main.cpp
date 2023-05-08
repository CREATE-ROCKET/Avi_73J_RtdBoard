#include <Arduino.h>

#include <SPICREATE.h>

#include "infrastructure/router.h"

void loop()
{
    Router1.icm20948Controller->Add(address);
}
