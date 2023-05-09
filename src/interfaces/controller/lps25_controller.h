#pragma once

#ifndef LPS25_CONTROLLER_H
#define LPS25_CONTROLLER_H

#include "../../domain/data.h"

#include "../../usecase/lps25_interactor.h"
#include "../../usecase/lps25_repository_usecase.h"

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/lps25_repository.h"

class LPS25Controller
{
private:
    LPS25Interactor *lps25Interactor;

public:
    LPS25Controller(LPS25Interactor *lps25Interactor) : lps25Interactor(lps25Interactor) {}

    bool Add(uint8_t addr);
    Data Get(uint8_t *rx);
};

LPS25Controller *NewLPS25Controller(SPIFlashHandler *spiflashHandler, LPS25Handler *lps25Handler)
{
    return new LPS25Controller(new LPS25Interactor(new LPS25RepositoryDATABASE(spiflashHandler, lps25Handler)));
}

bool LPS25Controller::Add(uint8_t addr)
{
    return lps25Interactor->AddData(addr);
}

Data LPS25Controller::Get(uint8_t *rx)
{
    lps25Interactor->GetData(rx);
    Data result;
    result.pressure[0] = rx[0];
    result.pressure[1] = rx[1];
    result.pressure[2] = rx[2];
    return result;
}

#endif
