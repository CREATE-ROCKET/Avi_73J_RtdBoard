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
    std::shared_ptr<LPS25Interactor> lps25Interactor;

public:
    LPS25Controller(std::shared_ptr<LPS25Interactor> lps25Interactor) : lps25Interactor(lps25Interactor) {}

    bool Add(uint8_t addr);
    Data Get(uint8_t *rx);
};

std::shared_ptr<LPS25Controller> NewLPS25Controller(std::shared_ptr<SPIFlashHandler> spiflashHandler, std::shared_ptr<LPS25Handler> lps25Handler);
// {
//     std::shared_ptr<LPS25RepositoryDATABASE> lps25Repository = std::make_shared<LPS25RepositoryDATABASE>(spiflashHandler, lps25Handler);
//     std::shared_ptr<LPS25Interactor> lps25Interactor = std::make_shared<LPS25Interactor>(lps25Repository);
//     return std::make_shared<LPS25Controller>(lps25Interactor);
// }

// bool LPS25Controller::Add(uint8_t addr)
// {
//     return lps25Interactor->AddData(addr);
// }

// Data LPS25Controller::Get(uint8_t *rx)
// {
//     lps25Interactor->GetData(rx);
//     Data result;
//     result.pressure[0] = rx[0];
//     result.pressure[1] = rx[1];
//     result.pressure[2] = rx[2];
//     return result;
// }

#endif
