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
    void GetData(int16_t *rx, uint8_t *rx_buf);
};

bool ICM20948Interactor::AddData(uint8_t addr)
{
    return icm20948Repository->SaveData(addr);
}

void ICM20948Interactor::GetData(int16_t *rx, uint8_t *rx_buf)
{
    icm20948Repository->GainData(rx, rx_buf);
}

#endif
