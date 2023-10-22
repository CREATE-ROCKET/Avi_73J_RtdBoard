#pragma once

#ifndef pressure_H
#define pressure_H
#include <Arduino.h>
#include <LPS25HB.h>

#include <iostream>
#include <memory>

#include "domain/setting.h"

class pressure {
   public:
    pressure() {
        lps25 = std::make_shared<LPS>();
        // LPS25HBの初期化
        lps25->begin(&SPIC2, LPSCS, SPIFREQ);
    }

    void Get(uint8_t *SPI_FlashBuff, int CountSPIFlashDataSetExistInBuff);

   private:
    std::shared_ptr<LPS> lps25;
};

void pressure::Get(uint8_t *SPI_FlashBuff, int CountSPIFlashDataSetExistInBuff) {
    uint8_t lps_rx[3] = {};
    // LPSの気圧をとる
    lps25->Get(lps_rx);
    for (int index = 28; index < 31; index++) {
        SPI_FlashBuff[32 * CountSPIFlashDataSetExistInBuff + index] = lps_rx[index - 28];
    }
}

#endif
