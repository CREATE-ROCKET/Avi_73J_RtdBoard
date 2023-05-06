#pragma once

#ifndef ACCEL_REPOSITORY_H
#define ACCEL_REPOSITORY_H

#include <Arduino.h>

#include "spiflash_handler.h"
#include "../../domain/data.h"
#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"



class FlashRepositoryDATABASE : public FlashRepository
{
public:
    // FlashRepositoryDATABASE(SPIFlashHandlerDATABASE *spiFlashHandler, ICM20948HandlerDATABASE *icm20948Handler) : FlashRepository(spiFlashHandler, icm20948Handler) {}
    FlashRepositoryDATABASE(SPIFlashHandlerDATABASE *spiFlashHandler) : FlashRepository(spiFlashHandler) {}

    bool SaveData(uint8_t addr, Data data) override;
    Data GetData(uint8_t addr) override;
};

bool FlashRepositoryDATABASE::SaveData(uint8_t addr, Data data)
{
    uint8_t tx[3];
    tx[0] = data.id;
    spiFlashHandler->write(addr, tx);
    return true;
}

Data FlashRepositoryDATABASE::GetData(uint8_t addr)
{
    uint8_t rx[3];
    spiFlashHandler->read(addr, rx);
    Data a;
    rx[0] = a.id;
    return a;
}

#endif