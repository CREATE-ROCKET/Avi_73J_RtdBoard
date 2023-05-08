#pragma once

#ifndef ICM20948_REPOSITORY_USECASE_H
#define ICM20948_REPOSITORY_USECASE_H

#include "../domain/data.h"

class ICM20948Repository
{
public:
    virtual bool SaveData(uint8_t addr) = 0;
};

#endif