#pragma once

#ifndef SPI_CREATE_H
#define SPI_CREATE_H

#include <SPICREATE.h>

class SPICREATEHandler
{
public:
    SPICREATE::SPICreate *SPI;
};

SPICREATEHandler *NewSPICreate()
{
    SPICREATE::SPICreate *targetSPI = new SPICREATE::SPICreate();
    SPICREATEHandler *targetSPICREATEHandler = new SPICREATEHandler();
    targetSPICREATEHandler->SPI = targetSPI;
    return targetSPICREATEHandler;
}

#endif