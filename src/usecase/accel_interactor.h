#pragma once

#ifndef ACCEL_INTERACTOR_H
#define ACCEL_INTERACTOR_H

#include <Arduino.h>

#include "../domain/accel.h"
#include "accel_repository_usecase.h"
#include "../interfaces/database/accel_repository.h"

class FlashInteractor
{
private:
    FlashRepository *flashRepository;

public:
    FlashInteractor(FlashRepository *flashRepository) :flashRepository(flashRepository) {}

    bool AddAccel(uint8_t addr, Accel accel);
    Accel OneAccel(uint8_t id);
    // Accels PageAccels(uint8_t id);
};

bool FlashInteractor::AddAccel(uint8_t addr, Accel accel)
{
    return accelRepository->SaveAccel(addr, accel);
}

Accel FlashInteractor::OneAccel(uint8_t id)
{
    return accelRepository->GetAccel(id);
}

// Accels FlashInteractor::PageAccels(uint8_t id)
// {
//     return accelRepository->GetAccels(id);
// }

#endif
