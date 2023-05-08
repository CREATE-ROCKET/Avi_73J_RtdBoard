#pragma once

#ifndef ICM20948_REPOSITORY_USECASE_H
#define ICM20948_REPOSITORY_USECASE_H

#include "../domain/data.h"

class ICM20948Repository
{
public:
    virtual bool SaveData(uint8_t addr) = 0;
    // virtual Data GetData(uint8_t id) = 0;
    // virtual bool DeleteData() = 0;
};

#endif