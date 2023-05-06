#pragma once

#ifndef ACCEL_CONTROLLER_H
#define ACCEL_CONTROLLER_H

#include <Arduino.h>

#include "../../domain/accel.h"

#include "../../usecase/flash_interactor.h"
#include "../../usecase/flash_repository_usecase.h"

#include "../database/spiflash_handler.h"
#include "../database/flash_repository.h"

class FlashController
{
private:
    FlashInteractor Interactor;

public:
    FlashController(SPIFlashHandlerDATABASE* handler) : Interactor(new FlashRepositoryDATABASE(handler)) {}

    bool Add(uint8_t addr, Accel accel);
    Accel Read(uint8_t id);
    // Accels ReadPage(uint8_t id);
};

FlashController *NewFlashController(SPIFlashHandlerDATABASE* handler)
{
    return new FlashController(handler);
}

bool FlashController::Add(uint8_t addr, Accel accel)
{
    return Interactor.AddAccel(addr, accel);
}

Accel FlashController::Read(uint8_t id)
{
    return Interactor.OneAccel(id);
}

// Accels FlashController::ReadPage(uint8_t id)
// {
//     return Interactor.PageAccels(id);
// }

#endif
