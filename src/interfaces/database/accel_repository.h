#pragma once

#ifndef ACCEL_REPOSITORY_H
#define ACCEL_REPOSITORY_H

#include <Arduino.h>

#include "spiflash_handler.h"
#include "../../domain/accel.h"
#include "../../usecase/accel_interactor.h"
#include "../../usecase/accel_repository_usecase.h"



class FlashRepositoryDATABASE : public FlashRepository
{
public:
    // FlashRepositoryDATABASE(SPIFlashHandlerDATABASE *spiFlashHandler, ICM20948HandlerDATABASE *icm20948Handler) : FlashRepository(spiFlashHandler, icm20948Handler) {}
    FlashRepositoryDATABASE(SPIFlashHandlerDATABASE *spiFlashHandler) : FlashRepository(spiFlashHandler) {}

    bool SaveAccel(uint8_t addr, Accel accel) override;
    Accel GetAccel(uint8_t addr) override;
    // Accels GetAccels(uint8_t id) override;
};

bool FlashRepositoryDATABASE::SaveAccel(uint8_t addr, Accel accel)
{
    uint8_t tx[3];
    tx[0] = accel.AccelX;
    tx[1] = accel.AccelY;
    tx[2] = accel.AccelZ;
    // icm20948Handler->Get();
    spiFlashHandler->write(addr, tx);
    return true;
}

Accel FlashRepositoryDATABASE::GetAccel(uint8_t addr)
{
    uint8_t rx[3];
    spiFlashHandler->read(addr, rx);
    Accel a;
    rx[0] = a.AccelX;
    rx[1] = a.AccelY;
    rx[2] = a.AccelZ;
    return a;
}

// Accels FlashRepositoryDATABASE::GetAccels(uint8_t id)
// {
//     spiFlashHandler->read(addr, rx);
//     Accels a;
//     for (int i = 0; i < 8; i++)
//     {
//         Accel accel;
//         accel.AccelX = rx[0];
//         accel.AccelY = rx[1];
//         accel.AccelZ = rx[2];
//         a.push_back(accel);
//     }
//     return a;
// }

#endif