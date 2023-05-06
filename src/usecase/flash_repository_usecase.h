#pragma once

#ifndef ACCEL_REPOSITORY_USECASE_H
#define ACCEL_REPOSITORY_USECASE_H

#include <Arduino.h>

#include "../domain/data.h"

class FlashRepository
{
public:
    SPIFlashHandlerDATABASE *spiFlashHandler;
    FlashRepository(SPIFlashHandlerDATABASE *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}

public:
    virtual bool SaveData(uint8_t addr, Data data) = 0;
    virtual Data GetData(uint8_t id) = 0;
};

#endif