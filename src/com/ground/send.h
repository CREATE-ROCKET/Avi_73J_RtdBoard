#pragma once

#ifndef Ground_Send_H
#define Ground_Send_H

#include <Arduino.h>

#include "domain/setting.h"

#define GroundSendPeriod 1

IRAM_ATTR void GroundSend(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    Serial3.begin(9600);
    while (!Serial3)
        ;
    for (;;) {
        std::unique_lock<std::mutex> lock(sendDataMutex);
        for (int i = 0; i < 256; i++) {
            // 送信
            Serial3.write(Send_Data[i]);
            // 配列の初期化
            Send_Data[i] = 0;
        }
        lock.unlock();
        Gimbal_data_count = 0;
        vTaskDelayUntil(&xLastWakeTime,
                        GroundSendPeriod / portTICK_PERIOD_MS);  // 1ms = 1000Hz
    }
}

#endif
