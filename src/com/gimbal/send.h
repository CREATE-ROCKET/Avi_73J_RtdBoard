#pragma once

#ifndef Gimbal_Send_H
#define Gimbal_Send_H

#include <Arduino.h>

void Gimbal_Send(char *command) {
    if (!Serial2) {
        Serial2.begin(9600);
        while (!Serial2)
            ;
    }
    Serial2.write(command);
}

#endif
