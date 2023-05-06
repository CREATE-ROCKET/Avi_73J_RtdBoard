#pragma once

#ifndef ICM20948_HANDLER_H
#define ICM20948_HANDLER_H

#include <Arduino.h>

#include "spicreatehandler.h"
#include "../interfaces/database/icm20948_handler.h"
#include <ICM20948.h>

class ICM20948Handler : public ICM20948HandlerDATABASE
{
public:
    ICM *icm20948;
    void begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq = 8000000);
    uint8_t WhoAmI();
    void Get(int16_t *rx, uint8_t *rx_buf);
};

ICM20948HandlerDATABASE *NewICM20948Handler()
{
    ICM *targetICM20948 = new ICM();
    ICM20948Handler *targetICM20948Handler = new ICM20948Handler();
    targetICM20948Handler->icm20948 = targetICM20948;
    return targetICM20948Handler;
}

void ICM20948Handler::begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq)
{
    icm20948->begin(targetSPI, cs, freq);
}

uint8_t ICM20948Handler::WhoAmI()
{
    return icm20948->WhoAmI();
}

void ICM20948Handler::Get(int16_t *rx, uint8_t *rx_buf)
{
    icm20948->Get(rx, rx_buf);
}

#endif

