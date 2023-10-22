#pragma once

#ifndef accel_H
#define accel_H
#include <Arduino.h>
#include <ICM20602.h>

#include <iostream>
#include <memory>

#include "domain/setting.h"

class accel {
   public:
    accel() {
        icm20602 = std::make_shared<ICM>();
        // ICM20948の初期化
        icm20602->begin(&SPIC2, ICMCS, SPIFREQ);
    }

    void Get(uint8_t *SPI_FlashBuff, int CountSPIFlashDataSetExistInBuff);

   private:
    std::shared_ptr<ICM> icm20602;
};

void accel::Get(uint8_t *SPI_FlashBuff, int CountSPIFlashDataSetExistInBuff) {
    int16_t Icm20948ReceiveData[6] = {};
    uint8_t Icm20948_rx_buf[12] = {};
    // 加速度をとる
    icm20602->Get(Icm20948ReceiveData, Icm20948_rx_buf);

    // ICM20948の加速度をとる
    for (int index = 10; index < 16; index++) {
        SPI_FlashBuff[32 * CountSPIFlashDataSetExistInBuff + index] = Icm20948_rx_buf[index - 10];
    }

    // ICM20948の角速度をとる
    for (int index = 16; index < 22; index++) {
        SPI_FlashBuff[32 * CountSPIFlashDataSetExistInBuff + index] = Icm20948_rx_buf[index - 10];
    }
}

#endif
