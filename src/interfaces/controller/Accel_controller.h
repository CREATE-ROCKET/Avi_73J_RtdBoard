#pragma once

#ifndef ACCEL_CONTROLLER_H
#define ACCEL_CONTROLLER_H

#include <Arduino.h>

#include "../../domain/accel.h"

#include "../../usecase/accel_interactor.h"
#include "../../usecase/accel_repository_usecase.h"

#include "../database/spiflash_handler.h"
#include "../database/accel_repository.h"

class AccelController
{
private:
    AccelInteractor Interactor;

public:
    AccelController(SPIFlashHandlerDATABASE* handler) : Interactor(new AccelRepositoryDATABASE(handler)) {}

    bool Add(uint8_t addr, Accel accel);
    Accel Read(uint8_t id);
    // Accels ReadPage(uint8_t id);
};

AccelController *NewAccelController(SPIFlashHandlerDATABASE* handler)
{
    return new AccelController(handler);
}

bool AccelController::Add(uint8_t addr, Accel accel)
{
    return Interactor.AddAccel(addr, accel);
}

Accel AccelController::Read(uint8_t id)
{
    return Interactor.OneAccel(id);
}

// Accels AccelController::ReadPage(uint8_t id)
// {
//     return Interactor.PageAccels(id);
// }

#endif
