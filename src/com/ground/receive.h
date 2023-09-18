#pragma once

#ifndef Ground_Receive_H
#define Ground_Receive_H

#include <Arduino.h>

#include "com/gimbal/send.h"

#define GroundPeriod 1

#define GROUND_COMMAND_START 'a'
#define GROUND_COMMAND_STOP 'b'

IRAM_ATTR void GroundReceive(void *parameters) {
    portTickType xLastWakeTime = xTaskGetTickCount();
    Serial3.begin(9600);
    while (!Serial3)
        ;
    char command[1];
    uint8_t GroundMode = 0;
    for (;;) {
        switch (GroundMode) {
            case 0:  // 待機モード
                if (Serial3.available() > 0) {
                    Serial3.readBytes(command, 1);
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
                                break;
                        }
                    }
                }
                break;
            case 1:  // 記録するモード
                if (Serial3.available() > 0) {
                    Serial3.read(command, 1);
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
                                break;
                        }
                    }
                }
                break;
            default:
                break;
        }
        vTaskDelayUntil(&xLastWakeTime,
                        GroundPeriod / portTICK_PERIOD_MS);  // 1ms = 1000Hz
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
//             break;
//     }
// }

#endif
