#pragma once

#ifndef ICM20948_CONTROLLER_H
#define ICM20948_CONTROLLER_H

#include "../../domain/data.h"

#include "../../usecase/icm20948_interactor.h"
#include "../../usecase/icm20948_repository_usecase.h"

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_repository.h"

class ICM20948Controller
{
private:
    ICM20948Interactor *icm20948Interactor;

public:
    // ICM20948Controller(ICM20948Interactor *icm20948Interactor) : Interactor(new ICM20948Interactor(ICM20948Interactor)) {}
    ICM20948Controller(ICM20948Interactor *icm20948Interactor) : icm20948Interactor(icm20948Interactor) {}

    bool Add(uint8_t addr);
    // Data Read(uint8_t id);
    // bool Erase();
};

ICM20948Controller *NewICM20948Controller(SPIFlashHandler *spiflashHandler, ICM20948Handler *icm20948Handler)
{
    return new ICM20948Controller(new ICM20948Interactor(new ICM20948RepositoryDATABASE(spiflashHandler, icm20948Handler)));
}

bool ICM20948Controller::Add(uint8_t addr)
{\
    return icm20948Interactor->AddData(addr);
}

// Data ICM20948Controller::Read(uint8_t id)
// {
//     return Interactor.OneData(id);
// }

// bool ICM20948Controller::Erase()
// {
//     return Interactor.EraseData();
// }

#endif
