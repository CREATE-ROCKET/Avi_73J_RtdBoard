#pragma once

#ifndef Ground_Receive_H
#define Ground_Receive_H

#include <Arduino.h>

#include <NEC920.hpp>

#include "../RFparam/RTD_PARAM.h"
#include "com/gimbal/send.h"
#include "ground_setting.h"

#define GroundPeriod 1

#define GROUND_COMMAND_START 'a'
#define GROUND_COMMAND_STOP 'b'

uint8_t j = 0x71;

IRAM_ATTR void GroundReceive(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    if (!isNec920Setup) {
        nec920.beginSerial(&Serial1, 38400, pin920Rx, pin920Tx);  // 38400
        nec920.setPin(pin920Reset, pin920Wakeup, pin920Mode);
        while (nec920.isBootFinished(400000) == 0)
            ;
        nec920.setRfConf(j, rtdRFparam::POWER, rtdRFparam::CHANNEL, rtdRFparam::RF_BAND, rtdRFparam::CS_MODE);
        isNec920Setup = true;
    }
    char command[1];
    // uint8_t GroundMode = 0;
    while ((nec920.isRecieveCmdResult()) && (!nec920.checkCmdResult(j++)))
        ;
    for (;;) {
        switch (GroundMode) {
            case 0:  // 待機モード
                if (nec920.recieve() > 0) {
                    if (nec920.isRecieveCmdData()) {
                        uint8_t tmpArr[256];
                        uint8_t datalength = nec920.getRecieveData(tmpArr);
                        // for (int i = 0; i < datalength; i++) {
                        //     Serial.printf("%02X,", tmpArr[i]);
                        // }
                        // datalengthが1だと仮定して
                        command[0] = tmpArr[0];
                    }
                    // Ground_command(command, GroundMode);
                    {
                        switch (command[0]) {
                            case GROUND_COMMAND_START:
                                Serial.println(GROUND_COMMAND_START);
                                Gimbal_Send(command);
                                GroundMode = 1;
                                break;
                            case GROUND_COMMAND_STOP:
                                Serial.println(GROUND_COMMAND_STOP);
                                Gimbal_Send(command);
                                GroundMode = 0;
                            default:
                                Serial.println(command);
                                Gimbal_Send(command);
                                break;
                        }
                    }
                }
                break;
            case 1:  // 記録するモード
                if (nec920.recieve() > 0) {
                    if (nec920.isRecieveCmdData()) {
                        uint8_t tmpArr[256];
                        uint8_t datalength = nec920.getRecieveData(tmpArr);
                        // for (int i = 0; i < datalength; i++) {
                        //     Serial.printf("%02X,", tmpArr[i]);
                        // }
                        // datalengthが1だと仮定して
                        command[0] = tmpArr[0];
                    }
                    // Ground_command(command, GroundMode);
                    {
                        switch (command[0]) {
                            case GROUND_COMMAND_START:
                                Serial.println(GROUND_COMMAND_START);
                                Gimbal_Send(command);
                                GroundMode = 1;
                                break;
                            case GROUND_COMMAND_STOP:
                                Serial.println(GROUND_COMMAND_STOP);
                                Gimbal_Send(command);
                                GroundMode = 0;
                            default:
                                Serial.println(command);
                                Gimbal_Send(command);
                                break;
                        }
                    }
                }
                break;
            default:
                break;
        }
        vTaskDelayUntil(&xLastWakeTime, GroundPeriod / portTICK_PERIOD_MS);  // 1ms = 1000Hz
    }
}

// void Ground_command(char *command, uint8_t GroundMode) {
//     switch (command[0]) {
//         case GROUND_COMMAND_START:
//             Serial.println(GROUND_COMMAND_START);
//             Gimbal_Send(command);
//             GroundMode = 1;
//             break;
//         case GROUND_COMMAND_STOP:
//             Serial.println(GROUND_COMMAND_STOP);
//             Gimbal_Send(command);
//             GroundMode = 0;
//         default:
//             Serial.println(command);
//             Gimbal_Send(command);
//             break;
//     }
// }

#endif
