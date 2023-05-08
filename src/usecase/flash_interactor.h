#pragma once

#ifndef FLASH_INTERACTOR_H
#define FLASH_INTERACTOR_H

#include "../domain/data.h"
#include "../usecase/flash_repository_usecase.h"
// #include "../interfaces/database/flash_repository.h"

// class FlashInteractor
// {
// private:
//     FlashRepository *flashRepository;

// public:
//     FlashInteractor(FlashRepository *flashRepository) :flashRepository(flashRepository) {}

//     bool AddData(uint8_t addr, Data data);
//     Data OneData(uint8_t id);
//     bool EraseData();
// };

// bool FlashInteractor::AddData(uint8_t addr, Data data)
// {
//     return flashRepository->SaveData(addr, data);
// }

// Data FlashInteractor::OneData(uint8_t id)
// {
//     return flashRepository->GetData(id);
// }

// bool FlashInteractor::EraseData()
// {
//     return flashRepository->DeleteData();
// }

#endif
