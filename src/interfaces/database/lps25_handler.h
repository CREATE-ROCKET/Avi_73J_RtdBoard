#pragma once

#ifndef LPS25_HANDLER_DATABASE_H
#define LPS25_HANDLER_DATABASE_H

class LPS25Handler
{
public:
    virtual void begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq = 8000000) = 0;
    virtual uint8_t WhoAmI() = 0;
    virtual void Get(uint8_t *rx) = 0;
};

#endif