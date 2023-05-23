#pragma once

#ifndef ICM20948_REPOSITORY_H
#define ICM20948_REPOSITORY_H

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_handler.h"
#include "../../domain/data.h"

#include <Arduino.h>

class ICM20948RepositoryDATABASE : public ICM20948Repository
{
private:
    std::shared_ptr<SPIFlashHandler> spiFlashHandler;
    std::shared_ptr<ICM20948Handler> icm20948Handler;

public:
    ICM20948RepositoryDATABASE(std::shared_ptr<SPIFlashHandler> spiFlashHandler, std::shared_ptr<ICM20948Handler> icm20948Handler)
        : spiFlashHandler(spiFlashHandler), icm20948Handler(icm20948Handler) {}

    bool SaveData(uint8_t addr) override;
    void GainData(int16_t *rx, uint8_t *rx_buf) override;
};

bool ICM20948RepositoryDATABASE::SaveData(uint8_t addr)
{
    int16_t rx[6] = {};
    uint8_t rx_buf[12] = {};
    icm20948Handler->Get(rx, rx_buf);
    spiFlashHandler->write(addr, rx_buf);
    return true;
}

void ICM20948RepositoryDATABASE::GainData(int16_t *rx, uint8_t *rx_buf)
{
    icm20948Handler->Get(rx, rx_buf);
}

#endif