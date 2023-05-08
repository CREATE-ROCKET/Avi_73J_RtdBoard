#pragma once

#ifndef ICM20948_REPOSITORY_H
#define ICM20948_REPOSITORY_H

#include <Arduino.h>

#include "spiflash_handler.h"
#include "../../domain/data.h"
#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"

class Icm20948RepositoryDATABASE : public Icm20948Repository
{
private:
    SPIFlashHandler *spiFlashHandler;

public:
    // Icm20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler, ICM20948Handler *icm20948Handler) : Icm20948Repository(spiFlashHandler, icm20948Handler) {}
    Icm20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}
    // Icm20948Repository(SPIFlashHandler *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}

    bool SaveData(uint8_t addr, Data data) override;
    // Data GetData(uint8_t addr) override;
    // bool DeleteData() override;
};

bool Icm20948RepositoryDATABASE::SaveData(uint8_t addr, Data data)
{
    uint8_t tx[3];
    tx[0] = data.id;
    spiFlashHandler->write(addr, tx);
    return true;
}

// Data Icm20948RepositoryDATABASE::GetData(uint8_t addr)
// {
//     uint8_t rx[3];
//     spiFlashHandler->read(addr, rx);
//     Data a;
//     rx[0] = a.id;
//     return a;
// }

// bool Icm20948RepositoryDATABASE::DeleteData()
// {
//     spiFlashHandler->erase();
//     return true;
// }

#endif