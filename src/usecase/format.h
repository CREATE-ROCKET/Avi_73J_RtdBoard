#pragma once

#ifndef format_H
#define format_H
#include <Arduino.h>
#include <H3LIS331.h>
#include <ICM20948.h>
#include <LPS25HB.h>
#include <Log67Timer.h>
#include <S25FL512S.h>
#include <SPICREATE.h>

#include <iostream>
#include <memory>

#include "domain/accel.h"
#include "domain/pressure.h"

class formatter {
   public:
    formatter() {
        Lps25 = std::make_shared<pressure>();
        icm20948 = std::make_shared<accel>();
        timer = std::make_shared<Log67Timer>();
    }

    void Format();

    // SPI_FlashBuffは送る配列
    // この配列をcontext.Contextのように扱う。たすきみたいなイメージ
    uint8_t SPI_FlashBuff[256] = {};

   private:
    // CountSPIFlashDataSetExistInBuffは列
    int CountSPIFlashDataSetExistInBuff = 0;

    // 時間
    unsigned long Record_time;

    // 気圧の回数の測定(5回に1回)
    uint8_t count_lps = 0;

    // LPS25HBの気圧をとるクラスのインスタンス化
    std::shared_ptr<pressure> Lps25;
    // ICM20948の加速度をとるクラスのインスタンス化
    std::shared_ptr<accel> icm20948;

    // Timerクラスのインスタンス化
    std::shared_ptr<Log67Timer> timer;
};

void formatter::Format() {
    // CountSPIFlashDataSetExistInBuffは列。indexは行。

    // 時間をとる
    if (timer->start_flag) {
        timer->start_time = micros();
        timer->start_flag = false;
    }
    Record_time = timer->Gettime_record();
    for (int index = 0; index < 4; index++) {
        SPI_FlashBuff[32 * CountSPIFlashDataSetExistInBuff + index] =
            0xFF & (Record_time >> (8 * index));
    }

    icm20948->Get(SPI_FlashBuff, CountSPIFlashDataSetExistInBuff);

    // LPSの気圧をとる
    if (count_lps % 20 == 0) {
        Lps25->Get(SPI_FlashBuff, CountSPIFlashDataSetExistInBuff);
        count_lps = 0;
    }

    count_lps++;
    CountSPIFlashDataSetExistInBuff++;

    // 8個のデータが溜まったらSPIFlashに書き込む
    if (CountSPIFlashDataSetExistInBuff >= 8) {
        // 列の番号の初期化
        CountSPIFlashDataSetExistInBuff = 0;

        return;
    }
}

#endif
