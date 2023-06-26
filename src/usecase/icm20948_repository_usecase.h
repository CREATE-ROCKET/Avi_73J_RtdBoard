#pragma once

#ifndef ICM20948_REPOSITORY_USECASE_H
#define ICM20948_REPOSITORY_USECASE_H

#include "../domain/data.h"
#include <Arduino.h>

class ICM20948Repository
{
public:
    virtual bool SaveData(uint8_t addr) = 0;
    virtual void GainData(int16_t *rx, uint8_t *rx_buf) = 0;
};

#endif