#pragma once

#ifndef s25fl512_H
#define s25fl512_H
#include <Arduino.h>
#include <H3LIS331.h>
#include <ICM20948.h>
#include <LPS25HB.h>
#include <Log67Timer.h>
#include <S25FL512S.h>
#include <SPICREATE.h>

#include <algorithm>
#include <iostream>
#include <memory>

#include "domain/setting.h"
#include "usecase/format.h"

#define WritePeriod 1

class s25fl512_writer {
   public:
    s25fl512_writer() {
        flash1 = std::make_shared<Flash>();
        formatter1 = std::make_shared<formatter>();
        flash1->begin(&SPIC1, flashCS, SPIFREQ);
        SPIFlashLatestAddress = flash1->setFlashAddress();
    }

    void Write();

   private:
    // センサのクラスのインスタンス化
    std::shared_ptr<Flash> flash1;
    std::shared_ptr<formatter> formatter1;
};

void s25fl512_writer::Write() {
    // データの取得と整形
    formatter1->Format();
    // 送信データの作成または更新
    std::copy(std::begin(formatter1->SPI_FlashBuff),
              std::end(formatter1->SPI_FlashBuff), std::begin(Send_Data));
    // データの書き込み
    flash1->write(SPIFlashLatestAddress, formatter1->SPI_FlashBuff);
    // アドレスの更新
    SPIFlashLatestAddress += 0x100;
}

IRAM_ATTR void DataWrite(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    std::shared_ptr<s25fl512_writer> s25fl512_writer1 =
        std::make_shared<s25fl512_writer>();
    for (;;) {
        if (GroundMode == 1) {
            s25fl512_writer1->Write();
        }
        vTaskDelayUntil(&xLastWakeTime,
                        WritePeriod / portTICK_PERIOD_MS);  // 1ms = 1000Hz
    }
}

#endif
