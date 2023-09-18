#pragma once

#ifndef Ground_Send_H
#define Ground_Send_H

#include <Arduino.h>

#include "domain/setting.h"

// #include "ICM20948.h"
// #include "LPS25HB.h"
// #include "NEC920.hpp"
// #include "RTD_PARAM.h"
// #include "S25FL512S.h"
// #include "SPICREATE.h"
// #include "esp_log.h"

uint8_t Gimbal_data_count = 0;

void Ground_Send(char *command_data) {
    if (!Serial3) {
        Serial3.begin(9600);
        while (!Serial3)
            ;
    }
    Send_Data[100 + Gimbal_data_count] = int(command_data);
    Gimbal_data_count++;
    if (Gimbal_data_count > 10) {
        for (int i = 0; i < 256; i++) {
            Serial3.write(Send_Data[i]);
        }
        Gimbal_data_count = 0;
    }
}

// static const char *TAG = "INIT";

// #define SCK 27
// #define MISO 33
// #define MOSI 26
// #define CS_PRESSURE 13
// #define CS_FLASH 32
// #define CS_IMU 25
// #define SPIFREQ 5000000

// SPICREATE::SPICreate spibus;
// LPS pressureSensor;
// Flash flash;
// ICM imu;

// NEC920 nec920;

// void setup() {
//     Serial.begin(115200);

//     spibus.begin(VSPI, SCK, MISO, MOSI);
//     ESP_LOGV(TAG, "SPIBUS");
//     pressureSensor.begin(&spibus, CS_PRESSURE, SPIFREQ);
//     ESP_LOGV(TAG, "pressure");
//     flash.begin(&spibus, CS_FLASH, SPIFREQ);
//     ESP_LOGV(TAG, "flash");
//     imu.begin(&spibus, CS_IMU, SPIFREQ);
//     ESP_LOGV(TAG, "IMU");

//     ESP_LOGV(TAG, "whoAmI p:%d, IMU:%d, Flash:%d", pressureSensor.WhoAmI(),
//              imu.WhoAmI(), 128);

//     uint8_t id[4] = {DST_1, DST_2, DST_3, DST_4};
//     nec920.setDstID(id);

//     Serial1.begin(115200, SERIAL_8N1, 18, 19);
//     nec920.setSerial(&Serial1);

//     nec920.setRfConf(POWER, CHANNEL, RF_BAND, CS_MODE);
// }

// uint8_t i = 0;

// void loop() {
//     uint8_t rxbff[254];
//     uint8_t rxlength = 0;
//     nec920.recieve();
//     rxlength = nec920.getRecievedData(rxbff);
//     if (rxlength > 0) {
//         ESP_LOGV(TAG, "data recieved");
//     }

//     if (nec920.isWirelessModuleDead()) {
//         ESP_LOGV(TAG, "nec920 stopped");
//     } else {
//         ESP_LOGV(TAG, "nec920 ok");
//     }

//     uint8_t parameter[2];
//     uint8_t parameterlength = 2;
//     parameter[0] = 255 - i;
//     parameter[1] = i++;

//     nec920.sendData(0x13, i, parameter, parameterlength);
//     ESP_LOGV(TAG, "send:%02X", i);

//     delay(500);
// }

#endif