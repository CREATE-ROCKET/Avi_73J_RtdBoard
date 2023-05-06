#pragma once

#ifndef ACCEL_INTERACTOR_H
#define ACCEL_INTERACTOR_H

#include <Arduino.h>

#include "../domain/accel.h"
#include "accel_repository_usecase.h"
#include "../interfaces/database/accel_repository.h"

class AccelInteractor
{
private:
    AccelRepository *accelRepository;

public:
    AccelInteractor(AccelRepository *accelRepository) : accelRepository(accelRepository) {}

    bool AddAccel(uint8_t addr, Accel accel);
    Accel OneAccel(uint8_t id);
    // Accels PageAccels(uint8_t id);
};

bool AccelInteractor::AddAccel(uint8_t addr, Accel accel)
{
    return accelRepository->SaveAccel(addr, accel);
}

Accel AccelInteractor::OneAccel(uint8_t id)
{
    return accelRepository->GetAccel(id);
}

// Accels AccelInteractor::PageAccels(uint8_t id)
// {
//     return accelRepository->GetAccels(id);
// }

#endif
