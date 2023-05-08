#pragma once

#ifndef ICM20948_CONTROLLER_H
#define ICM20948_CONTROLLER_H

#include <Arduino.h>

#include "../../domain/data.h"

#include "../../usecase/icm20948_interactor.h"
#include "../../usecase/icm20948_repository_usecase.h"

#include "../database/spiflash_handler.h"
#include "../database/icm20948_repository.h"

class Icm20948Controller
{
private:
    Icm20948Interactor *icm20948Interactor;

public:
    // Icm20948Controller(Icm20948Interactor *icm20948Interactor) : Interactor(new Icm20948Interactor(Icm20948Interactor)) {}
    Icm20948Controller(Icm20948Interactor *icm20948Interactor) : icm20948Interactor(icm20948Interactor) {}

    bool Add(uint8_t addr, Data data);
    // Data Read(uint8_t id);
    // bool Erase();
};

Icm20948Controller *NewIcm20948Controller(SPIFlashHandler *handler)
{
    return new Icm20948Controller(new Icm20948Interactor(new Icm20948RepositoryDATABASE(handler)));
}

bool Icm20948Controller::Add(uint8_t addr, Data data)
{
    return icm20948Interactor->AddData(addr, data);
}

// Data Icm20948Controller::Read(uint8_t id)
// {
//     return Interactor.OneData(id);
// }

// bool Icm20948Controller::Erase()
// {
//     return Interactor.EraseData();
// }

#endif
