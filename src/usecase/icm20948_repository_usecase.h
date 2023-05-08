#pragma once

#ifndef ICM20948_REPOSITORY_USECASE_H
#define ICM20948_REPOSITORY_USECASE_H

#include <Arduino.h>

#include "../domain/data.h"

class Icm20948Repository
{
public:
    SPIFlashHandlerDATABASE *spiFlashHandler;
    // Icm20948Repository(SPIFlashHandlerDATABASE *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}

public:
    virtual bool SaveData(uint8_t addr, Data data) = 0;
    // virtual Data GetData(uint8_t id) = 0;
    // virtual bool DeleteData() = 0;
};

#endif