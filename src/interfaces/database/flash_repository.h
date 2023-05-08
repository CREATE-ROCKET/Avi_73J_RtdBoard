#pragma once

#ifndef FLASH_REPOSITORY_H
#define FLASH_REPOSITORY_H

#include "../../interfaces/database/spiflash_handler.h"
#include "../../domain/data.h"
#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"



// class FlashRepositoryDATABASE : public FlashRepository
// {
// public:
//     // FlashRepositoryDATABASE(SPIFlashHandler *SPIFlashHandlerDATABASE, ICM20948Handler *icm20948Handler) : FlashRepository(SPIFlashHandlerDATABASE, icm20948Handler) {}
//     FlashRepositoryDATABASE(SPIFlashHandler *SPIFlashHandlerDATABASE) : FlashRepository(SPIFlashHandlerDATABASE) {}

//     bool SaveData(uint8_t addr, Data data) override;
//     Data GetData(uint8_t addr) override;
//     bool DeleteData() override;
// };

// bool FlashRepositoryDATABASE::SaveData(uint8_t addr, Data data)
// {
//     uint8_t tx[3];
//     tx[0] = data.id;
//     SPIFlashHandlerDATABASE->write(addr, tx);
//     return true;
// }

// Data FlashRepositoryDATABASE::GetData(uint8_t addr)
// {
//     uint8_t rx[3];
//     SPIFlashHandlerDATABASE->read(addr, rx);
//     Data a;
//     rx[0] = a.id;
//     return a;
// }

// bool FlashRepositoryDATABASE::DeleteData()
// {
//     SPIFlashHandlerDATABASE->erase();
//     return true;
// }

#endif