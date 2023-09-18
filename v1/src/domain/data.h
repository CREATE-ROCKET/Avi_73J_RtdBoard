#pragma once

#ifndef DATA_H
#define DATA_H

class Data
{
public:
    uint8_t accel[3];
    uint8_t gyro[3];
    uint8_t mag[3];
    uint8_t pressure[3];
};

#endif