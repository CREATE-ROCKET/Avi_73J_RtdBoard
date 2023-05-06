#pragma once

#ifndef ICM20948_HANDLER_DATABASE_H
#define ICM20948_HANDLER_DATABASE_H

#include <Arduino.h>

class ICM20948HandlerDATABASE
{
public:
    virtual void begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq = 8000000) = 0;
    virtual uint8_t WhoAmI() = 0;
    virtual void Get(int16_t *rx, uint8_t *rx_buf) = 0;
};

#endif