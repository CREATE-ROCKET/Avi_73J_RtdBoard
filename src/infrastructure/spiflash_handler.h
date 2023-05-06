#pragma once

#ifndef SPIFLASH_HANDLER_H
#define SPIFLASH_HANDLER_H

#include <Arduino.h>

#include "spicreatehandler.h"
#include "../interfaces/database/spiflash_handler.h"
#include <S25FL512S.h>

class SPIFlashHandler : public SPIFlashHandlerDATABASE
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

SPIFlashHandlerDATABASE *NewSPIFlashHandler()
{
    Flash *targetFlash = new Flash();
    SPIFlashHandler *targetSPIFlashHandler = new SPIFlashHandler();
    targetSPIFlashHandler->flash = targetFlash;
    return targetSPIFlashHandler;
}

void SPIFlashHandler::begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq)
{
    flash->begin(targetSPI, cs, freq);
}

uint32_t SPIFlashHandler::checkAddress(uint32_t FlashAddress)
{
    return flash->checkAddress(FlashAddress);
}

uint32_t SPIFlashHandler::setFlashAddress()
{
    return flash->setFlashAddress();
}

void SPIFlashHandler::erase()
{
    flash->erase();
}

void SPIFlashHandler::write(uint32_t addr, uint8_t *tx)
{
    flash->write(addr, tx);
}

void SPIFlashHandler::read(uint32_t addr, uint8_t *rx)
{
    flash->read(addr, rx);
}

#endif
