#pragma once

#ifndef Ground_Send_H
#define Ground_Send_H

#include <Arduino.h>

#include <NEC920.hpp>

#include "../../domain/setting.h"
#include "../RFparam/RTD_PARAM.h"
#include "domain/setting.h"

#define GroundSendPeriod 40

IRAM_ATTR void GroundSend(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    if (!isNec920Setup) {
        nec920.beginSerial(&Serial1, 38400, pin920Rx, pin920Tx);  // 38400
        nec920.setPin(pin920Reset, pin920Wakeup, pin920Mode);
        while (nec920.isBootFinished(400000) == 0)
            ;
        nec920.setRfConf(j, rtdRFparam::POWER, rtdRFparam::CHANNEL, rtdRFparam::RF_BAND, rtdRFparam::CS_MODE);
        isNec920Setup = true;
    }
    for (;;) {
        std::unique_lock<std::mutex> lock(sendDataMutex);
        // for (int i = 0; i < 256; i++) {
        //     // 送信
        //     Serial3.write(Send_Data[i]);
        //     // 配列の初期化
        //     Send_Data[i] = 0;
        // }
        if (nec920.canSendMsgCheck()) {
            uint8_t dstID[4] = {rtdRFparam::DST_1, rtdRFparam::DST_2, rtdRFparam::DST_3, rtdRFparam::DST_4};
            // uint8_t parameter[1] = {0x71};
            nec920.sendTxCmd(0x13, j, dstID, Send_Data, 1);
        }
        lock.unlock();
        Gimbal_data_count = 0;
        vTaskDelayUntil(&xLastWakeTime, GroundSendPeriod / portTICK_PERIOD_MS);  // 40ms = 25Hz
    }
}

#endif
