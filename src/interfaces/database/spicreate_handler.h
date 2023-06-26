#pragma once

#ifndef SPICREATE_HANDLER_DATABASE_H
#define SPICREATE_HANDLER_DATABASE_H

#include <Arduino.h>
#include <SPICREATE.h>

class SPICREATEHandler
{
public:
    virtual bool begin(uint8_t spi_bus = HSPI, int8_t sck = -1, int8_t miso = -1, int8_t mosi = -1, uint32_t f = 8000000) = 0;
    virtual bool end() = 0;

    virtual int addDevice(spi_device_interface_config_t *if_cfg, int cs) = 0;
    virtual bool rmDevice(int deviceHandle) = 0;

    virtual uint8_t readByte(uint8_t addr, int deviceHandle) = 0;
    virtual void sendCmd(uint8_t cmd, int deviceHandle) = 0;
    virtual void setReg(uint8_t addr, uint8_t data, int deviceHandle) = 0;

    virtual void transmit(uint8_t *tx, int size, int deviceHandle) = 0;
    virtual void transmit(uint8_t *tx, uint8_t *rx, int size, int deviceHandle) = 0;
    virtual void transmit(spi_transaction_t *transaction, int deviceHandle) = 0;

    virtual void pollTransmit(spi_transaction_t *transaction, int deviceHandle) = 0;
};

#endif