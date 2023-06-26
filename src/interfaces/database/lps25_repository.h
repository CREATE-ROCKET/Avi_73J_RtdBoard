#pragma once

#ifndef LPS25_REPOSITORY_H
#define LPS25_REPOSITORY_H

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/lps25_handler.h"
#include "../../usecase/lps25_repository_usecase.h"
#include "../../domain/data.h"

#include <Arduino.h>
#include <memory>

class LPS25RepositoryDATABASE : public LPS25Repository
{
private:
    std::shared_ptr<SPIFlashHandler> spiFlashHandler;
    std::shared_ptr<LPS25Handler> lps25Handler;

public:
    LPS25RepositoryDATABASE(std::shared_ptr<SPIFlashHandler> spiFlashHandler, std::shared_ptr<LPS25Handler> lps25Handler)
        : spiFlashHandler(spiFlashHandler), lps25Handler(lps25Handler) {}

    bool SaveData(uint8_t addr) override;
    void GainData(uint8_t *rx) override;
};

// bool LPS25RepositoryDATABASE::SaveData(uint8_t addr)
// {
//     uint8_t rx[3] = {};
//     lps25Handler->Get(rx);
//     spiFlashHandler->write(addr, rx);
//     return true;
// }

// void LPS25RepositoryDATABASE::GainData(uint8_t *rx)
// {
//     lps25Handler->Get(rx);
// }

#endif