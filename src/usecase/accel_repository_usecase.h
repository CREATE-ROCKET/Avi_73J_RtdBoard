#pragma once

#ifndef ACCEL_REPOSITORY_USECASE_H
#define ACCEL_REPOSITORY_USECASE_H

#include <Arduino.h>

#include "../domain/accel.h"

class AccelRepository
{
public:
    SPIFlashHandlerDATABASE *spiFlashHandler;
    // ICM20948HandlerDATABASE *icm20948Handler;
    // AccelRepository(SPIFlashHandlerDATABASE *spiFlashHandler, ICM20948HandlerDATABASE *icm20948Handler) : spiFlashHandler(spiFlashHandler), icm20948Handler(icm20948Handler) {}
    AccelRepository(SPIFlashHandlerDATABASE *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}

public:
    virtual bool SaveAccel(uint8_t addr, Accel accel) = 0;
    virtual Accel GetAccel(uint8_t id) = 0;
    // virtual Accels GetAccels(uint8_t id) = 0;
};

#endif