#pragma once

#ifndef Gimbal_Receive_H
#define Gimbal_Receive_H

#include <Arduino.h>

#include "com/ground/send.h"

#define GimbalPeriod 1

#define GIMBAL_COMMAND_START 'a'
#define GIMBAL_COMMAND_STOP 'b'

IRAM_ATTR void GimbalReceive(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    Serial2.begin(9600);
    while (!Serial2)
        ;
    char command[1];
    uint8_t GimbalMode = 0;
    for (;;) {
        switch (GimbalMode) {
            case 0:  // コマンドを受け取るモード
                if (Serial2.available() > 0) {
                    Serial2.readBytes(command, 1);
                    // Gimbal_command(command, GimbalMode);
                    {
                        switch (command[0]) {
                            case GIMBAL_COMMAND_START:
                                Serial.println(GIMBAL_COMMAND_START);
                                GimbalMode = 1;
                                break;
                            case GIMBAL_COMMAND_STOP:
                                Serial.println(GIMBAL_COMMAND_STOP);
                                GimbalMode = 0;
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case 1:  // データを受け取るモード
                if (Serial2.available() > 0) {
                    Serial2.readBytes(command, 1);
                    // Gimbal_command(command, GimbalMode);
                    {
                        switch (command[0]) {
                            case GIMBAL_COMMAND_START:
                                Serial.println(GIMBAL_COMMAND_START);
                                GimbalMode = 1;
                                break;
                            case GIMBAL_COMMAND_STOP:
                                Serial.println(GIMBAL_COMMAND_STOP);
                                GimbalMode = 0;
                                break;
                            default:
                                break;
                        }
                    }
                }
                Ground_Send_Stack(command);
                break;
            default:
                break;
        }
        vTaskDelayUntil(&xLastWakeTime,
                        GimbalPeriod / portTICK_PERIOD_MS);  // 1ms = 1000Hz
    }
}

// void Gimbal_command(char *command, uint8_t GimbalMode) {
//     switch (command[0]) {
//         case GIMBAL_COMMAND_START:
//             Serial.println(GIMBAL_COMMAND_START);
//             GimbalMode = 1;
//             break;
//         case GIMBAL_COMMAND_STOP:
//             Serial.println(GIMBAL_COMMAND_STOP);
//             GimbalMode = 0;
//             break;
//         default:
//             break;
//     }
// }

#endif
