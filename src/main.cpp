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

    int16_t rx[6] = {};
    uint8_t rx_buf[12] = {};
    Data result = Router1.icm20948Controller->Get(rx, rx_buf);
    Serial.println(result.accel[0]);
    Serial.println(result.accel[1]);
    Serial.println(result.accel[2]);

    uint8_t rx2[3] = {};
    Data result2 = Router1.lps25Controller->Get(rx2);
    Serial.println(result2.pressure[0]);
    Serial.println(result2.pressure[1]);
    Serial.println(result2.pressure[2]);
}
