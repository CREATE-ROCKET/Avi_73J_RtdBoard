#pragma once

#ifndef ICM20948_REPOSITORY_H
#define ICM20948_REPOSITORY_H

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_handler.h"
#include "../../domain/data.h"
#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"

class ICM20948RepositoryDATABASE : public ICM20948Repository
{
private:
    SPIFlashHandler *spiFlashHandler;
    ICM20948Handler *icm20948Handler;

public:
    // ICM20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler, ICM20948Handler *icm20948Handler) : ICM20948Repository(spiFlashHandler, icm20948Handler) {}
    // ICM20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler) : spiFlashHandler(spiFlashHandler) {}
    // ICM20948RepositoryDATABASE(ICM20948Handler *icm20948Handler) : icm20948Handler(icm20948Handler) {}
    ICM20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler, ICM20948Handler *icm20948Handler) : spiFlashHandler(spiFlashHandler), icm20948Handler(icm20948Handler) {}

    bool SaveData(uint8_t addr) override;
    // Data GetData(uint8_t addr) override;
    // bool DeleteData() override;
};

bool ICM20948RepositoryDATABASE::SaveData(uint8_t addr)
{
    int16_t rx[3];
    uint8_t rx_buf[3];
    icm20948Handler->Get(rx, rx_buf);
    spiFlashHandler->write(addr, rx_buf);
    return true;
}

// Data ICM20948RepositoryDATABASE::GetData(uint8_t addr)
// {
//     uint8_t rx[3];
//     spiFlashHandler->read(addr, rx);
//     Data a;
//     rx[0] = a.id;
//     return a;
// }

// bool ICM20948RepositoryDATABASE::DeleteData()
// {
//     spiFlashHandler->erase();
//     return true;
// }

#endif