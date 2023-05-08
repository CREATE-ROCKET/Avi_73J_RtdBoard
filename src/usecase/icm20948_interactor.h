#pragma once

#ifndef ICM20948_INTERACTOR_H
#define ICM20948_INTERACTOR_H

#include <Arduino.h>

#include "../domain/data.h"
#include "icm20948_repository_usecase.h"
#include "../interfaces/database/icm20948_repository.h"

class Icm20948Interactor
{
private:
    Icm20948Repository *icm20948Repository;

public:
    Icm20948Interactor(Icm20948Repository *icm20948Repository) : icm20948Repository(icm20948Repository) {}

    bool AddData(uint8_t addr, Data data);
    // Data OneData(uint8_t id);
    // bool EraseData();
};

bool Icm20948Interactor::AddData(uint8_t addr, Data data)
{
    return icm20948Repository->SaveData(addr, data);
}

// Data Icm20948Interactor::OneData(uint8_t id)
// {
//     return icm20948Repository->GetData(id);
// }

// bool Icm20948Interactor::EraseData()
// {
//     return icm20948Repository->DeleteData();
// }

#endif
