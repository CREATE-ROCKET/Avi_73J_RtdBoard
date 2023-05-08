#pragma once

#ifndef ICM20948_REPOSITORY_H
#define ICM20948_REPOSITORY_H

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_handler.h"
#include "../../domain/data.h"

class ICM20948RepositoryDATABASE : public ICM20948Repository
{
private:
    SPIFlashHandler *spiFlashHandler;
    ICM20948Handler *icm20948Handler;

public:
    ICM20948RepositoryDATABASE(SPIFlashHandler *spiFlashHandler, ICM20948Handler *icm20948Handler) : spiFlashHandler(spiFlashHandler), icm20948Handler(icm20948Handler) {}

    bool SaveData(uint8_t addr) override;
};

bool ICM20948RepositoryDATABASE::SaveData(uint8_t addr)
{
    int16_t rx[3];
    uint8_t rx_buf[3];
    icm20948Handler->Get(rx, rx_buf);
    spiFlashHandler->write(addr, rx_buf);
    return true;
}

#endif