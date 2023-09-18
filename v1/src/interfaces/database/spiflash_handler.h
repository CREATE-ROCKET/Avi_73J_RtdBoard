#pragma once

#ifndef SPIFLASH_HANDLER_DATABASE_H
#define SPIFLASH_HANDLER_DATABASE_H

class SPIFlashHandler
{
public:
    virtual void begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq = 8000000) = 0;
    virtual uint32_t checkAddress(uint32_t FlashAddress) = 0;
    virtual uint32_t setFlashAddress() = 0;
    virtual void erase() = 0;
    virtual void write(uint32_t addr, uint8_t *tx) = 0;
    virtual void read(uint32_t addr, uint8_t *rx) = 0;
};

#endif