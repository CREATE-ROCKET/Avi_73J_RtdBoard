#pragma once

#ifndef SPI_CREATE_H
#define SPI_CREATE_H

#include <Arduino.h>
#include <SPICREATE.h>

class SPICREATEHadndler
{
public:
    SPICREATE::SPICreate *SPI;
};

SPICREATEHadndler *NewSPICreate()
{
    SPICREATE::SPICreate *targetSPI = new SPICREATE::SPICreate();
    SPICREATEHadndler *targetSPICREATEHadndler = new SPICREATEHadndler();
    targetSPICREATEHadndler->SPI = targetSPI;
    return targetSPICREATEHadndler;
}

#endif