#pragma once

#ifndef FLASH_CONTROLLER_H
#define FLASH_CONTROLLER_H

#include <Arduino.h>

#include "../../domain/data.h"

#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"

#include "../database/spiflash_handler.h"
#include "../database/flash_repository.h"

// class FlashController
// {
// private:
//     FlashInteractor Interactor;

// public:
//     FlashController(SPIFlashHandler *handler) : Interactor(new FlashRepositoryDATABASE(handler)) {}

//     bool Add(uint8_t addr, Data data);
//     Data Read(uint8_t id);
//     bool Erase();
// };

// FlashController *NewFlashController(SPIFlashHandler *handler)
// {
//     return new FlashController(handler);
// }

// bool FlashController::Add(uint8_t addr, Data data)
// {
//     return Interactor.AddData(addr, data);
// }

// Data FlashController::Read(uint8_t id)
// {
//     return Interactor.OneData(id);
// }

// bool FlashController::Erase()
// {
//     return Interactor.EraseData();
// }

#endif
