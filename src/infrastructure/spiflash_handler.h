#pragma once

#ifndef SPIFLASH_HANDLER_H
#define SPIFLASH_HANDLER_H

#include "spicreatehandler.h"
#include "../interfaces/database/spiflash_handler.h"
#include <S25FL512S.h>

class SPIFlashHandlerDATABASE : public SPIFlashHandler
{
public:
    Flash *flash;
    void begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq = 8000000) override;
    uint32_t checkAddress(uint32_t FlashAddress) override;
    uint32_t setFlashAddress() override;
    void erase() override;
    void write(uint32_t addr, uint8_t *tx) override;
    void read(uint32_t addr, uint8_t *rx) override;
};

SPIFlashHandler *NewSPIFlashHandlerDATABASE()
{
    Flash *targetFlash = new Flash();
    SPIFlashHandlerDATABASE *targetSPIFlashHandlerDATABASE = new SPIFlashHandlerDATABASE();
    targetSPIFlashHandlerDATABASE->flash = targetFlash;
    return targetSPIFlashHandlerDATABASE;
}

void SPIFlashHandlerDATABASE::begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq)
{
    flash->begin(targetSPI, cs, freq);
}

uint32_t SPIFlashHandlerDATABASE::checkAddress(uint32_t FlashAddress)
{
    return flash->checkAddress(FlashAddress);
}

uint32_t SPIFlashHandlerDATABASE::setFlashAddress()
{
    return flash->setFlashAddress();
}

void SPIFlashHandlerDATABASE::erase()
{
    flash->erase();
}

void SPIFlashHandlerDATABASE::write(uint32_t addr, uint8_t *tx)
{
    flash->write(addr, tx);
}

void SPIFlashHandlerDATABASE::read(uint32_t addr, uint8_t *rx)
{
    flash->read(addr, rx);
}

#endif
