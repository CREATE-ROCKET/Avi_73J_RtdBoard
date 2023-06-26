#include "icm20948_interactor.h"

#include "../domain/data.h"
#include "../usecase/icm20948_repository_usecase.h"

bool ICM20948Interactor::AddData(uint8_t addr)
{
    return icm20948Repository->SaveData(addr);
}

void ICM20948Interactor::GetData(int16_t *rx, uint8_t *rx_buf)
{
    icm20948Repository->GainData(rx, rx_buf);
}