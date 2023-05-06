#pragma once

#ifndef ACCEL_INTERACTOR_H
#define ACCEL_INTERACTOR_H

#include <Arduino.h>

#include "../domain/data.h"
#include "flash_repository_usecase.h"
#include "../interfaces/database/flash_repository.h"

class FlashInteractor
{
private:
    FlashRepository *flashRepository;

public:
    FlashInteractor(FlashRepository *flashRepository) :flashRepository(flashRepository) {}

    bool AddData(uint8_t addr, Data data);
    Data OneData(uint8_t id);
};

bool FlashInteractor::AddData(uint8_t addr, Data data)
{
    return flashRepository->SaveData(addr, data);
}

Data FlashInteractor::OneData(uint8_t id)
{
    return flashRepository->GetData(id);
}

#endif
