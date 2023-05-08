#include <Arduino.h>

#include <SPICREATE.h>

#include "infrastructure/router.h"

void loop()
{
    bool check = Router1.icm20948Controller->Add(address);
    if (check)
    {
        Serial.println("Success");
    }
    else
    {
        Serial.println("Failed");
    }

    delay(1000);

    int16_t rx[3];
    uint8_t rx_buf[3];
    Data result = Router1.icm20948Controller->Get(rx, rx_buf);
    Serial.println(result.accel[0]);
    Serial.println(result.accel[1]);
    Serial.println(result.accel[2]);
}
