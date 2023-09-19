#pragma once

#ifndef Ground_Data_Stack_H
#define Ground_Data_Stack_H

#include <mutex>

#include "domain/setting.h"

uint8_t Gimbal_data_count = 0;
uint8_t cash_len = 0;
uint8_t cash[256];

// ここで10は1回で送るGimbalのデータの数
const uint8_t OnceNumberOfGimbalData = 10;
const uint8_t OnceNumberOfDataExceptGimbalData = 100;

void Ground_Send_Stack(char *command_data) {
    std::unique_lock<std::mutex> lock(sendDataMutex);
    // Gimbalデータがなく、cashがあるとき
    if ((Gimbal_data_count == 0) && (cash_len > 0)) {
        // cashの量が一回で送れる量以上にあるとき
        if (cash_len > OnceNumberOfGimbalData) {
            // 一回で送れる量を送信
            for (int i = 0; i < OnceNumberOfGimbalData; i++) {
                Send_Data[OnceNumberOfDataExceptGimbalData + i] = cash[i];
            }
            // cashの中身をずらす
            for (int i = 0; i < cash_len - OnceNumberOfGimbalData; i++) {
                cash[i] = cash[i + OnceNumberOfGimbalData];
            }
            cash_len -= OnceNumberOfGimbalData;
        } else {  // cashの量が一回で送れる量以下のとき
            // cashの中身を送信
            for (int i = 0; i < cash_len; i++) {
                Send_Data[OnceNumberOfDataExceptGimbalData + i] = cash[i];
            }
            cash_len = 0;
        }
    }
    // Gimbalデータが1回で送れる量以下のとき
    if (Gimbal_data_count < OnceNumberOfGimbalData) {
        Send_Data[OnceNumberOfDataExceptGimbalData + Gimbal_data_count] =
            command_data[0];
        Gimbal_data_count++;
    } else {  // 1回で送れる量以上にGimbalデータがあるとき
        // cashが満タンでないとき
        if (cash_len < 256) {
            cash[cash_len] = command_data[0];
            cash_len++;
        }
        // cashが満タンのときデータは捨てる
    }
    lock.unlock();
}

#endif
