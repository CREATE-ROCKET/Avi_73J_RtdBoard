#pragma once

#ifndef ICM20948_INTERACTOR_H
#define ICM20948_INTERACTOR_H

#include "../domain/data.h"
#include "../usecase/icm20948_repository_usecase.h"

class ICM20948Interactor
{
private:
    ICM20948Repository *icm20948Repository;

public:
    ICM20948Interactor(ICM20948Repository *icm20948Repository) : icm20948Repository(icm20948Repository) {}


    bool AddData(uint8_t addr);
    // Data OneData(uint8_t id);
    // bool EraseData();
};

bool ICM20948Interactor::AddData(uint8_t addr)
{
    return icm20948Repository->SaveData(addr);
}

// Data ICM20948Interactor::OneData(uint8_t id)
// {
//     return icm20948Repository->GetData(id);
// }

// bool ICM20948Interactor::EraseData()
// {
//     return icm20948Repository->DeleteData();
// }

#endif
