#pragma once

#ifndef SPI_CREATE_H
#define SPI_CREATE_H

#include "../interfaces/database/spicreate_handler.h"
#include <SPICREATE.h>
#include <memory>

class SPICREATEHandlerDATABASE : public SPICREATEHandler
{
public:
    std::shared_ptr<SPICREATE::SPICreate> SPI;
    bool begin(uint8_t spi_bus = HSPI, int8_t sck = -1, int8_t miso = -1, int8_t mosi = -1, uint32_t f = 8000000) override;
    bool end() override;

    int addDevice(spi_device_interface_config_t *if_cfg, int cs) override;
    bool rmDevice(int deviceHandle) override;

    uint8_t readByte(uint8_t addr, int deviceHandle) override;
    void sendCmd(uint8_t cmd, int deviceHandle) override;
    void setReg(uint8_t addr, uint8_t data, int deviceHandle) override;

    void transmit(uint8_t *tx, int size, int deviceHandle) override;
    void transmit(uint8_t *tx, uint8_t *rx, int size, int deviceHandle) override;
    void transmit(spi_transaction_t *transaction, int deviceHandle) override;

    void pollTransmit(spi_transaction_t *transaction, int deviceHandle) override;
};

std::shared_ptr<SPICREATEHandlerDATABASE> NewSPICreate()
{
    std::shared_ptr<SPICREATE::SPICreate> targetSPI = std::make_shared<SPICREATE::SPICreate>();
    std::shared_ptr<SPICREATEHandlerDATABASE> targetSPICREATEHandlerDATABASE = std::make_shared<SPICREATEHandlerDATABASE>();
    targetSPICREATEHandlerDATABASE->SPI = targetSPI;
    return targetSPICREATEHandlerDATABASE;
}

bool SPICREATEHandlerDATABASE::begin(uint8_t spi_bus, int8_t sck, int8_t miso, int8_t mosi, uint32_t f)
{
    return SPI->begin(spi_bus, sck, miso, mosi, f);
}

bool SPICREATEHandlerDATABASE::end()
{
    return SPI->end();
}

int SPICREATEHandlerDATABASE::addDevice(spi_device_interface_config_t *if_cfg, int cs)
{
    return SPI->addDevice(if_cfg, cs);
}

bool SPICREATEHandlerDATABASE::rmDevice(int deviceHandle)
{
    return SPI->rmDevice(deviceHandle);
}

uint8_t SPICREATEHandlerDATABASE::readByte(uint8_t addr, int deviceHandle)
{
    return SPI->readByte(addr, deviceHandle);
}

void SPICREATEHandlerDATABASE::sendCmd(uint8_t cmd, int deviceHandle)
{
    SPI->sendCmd(cmd, deviceHandle);
}

void SPICREATEHandlerDATABASE::setReg(uint8_t addr, uint8_t data, int deviceHandle)
{
    SPI->setReg(addr, data, deviceHandle);
}

void SPICREATEHandlerDATABASE::transmit(uint8_t *tx, int size, int deviceHandle)
{
    SPI->transmit(tx, size, deviceHandle);
}

void SPICREATEHandlerDATABASE::transmit(uint8_t *tx, uint8_t *rx, int size, int deviceHandle)
{
    SPI->transmit(tx, rx, size, deviceHandle);
}

void SPICREATEHandlerDATABASE::transmit(spi_transaction_t *transaction, int deviceHandle)
{
    SPI->transmit(transaction, deviceHandle);
}

void SPICREATEHandlerDATABASE::pollTransmit(spi_transaction_t *transaction, int deviceHandle)
{
    SPI->pollTransmit(transaction, deviceHandle);
}

#endif