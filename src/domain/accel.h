#pragma once

#ifndef ACCEL_H
#define ACCEL_H

#include <string>
#include <vector>
#include <Arduino.h>

class Accel
{
public:
    uint8_t AccelX;
    uint8_t AccelY;
    uint8_t AccelZ;
};

// std::vector<Accel> Accels;

#endif

// 1ページに書き込まれている加速度の数が8