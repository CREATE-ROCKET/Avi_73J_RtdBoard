#include "spiflash_handler.h"

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/spiflash_handler.h"

std::shared_ptr<SPIFlashHandlerDATABASE> NewSPIFlashHandlerDATABASE()
{
    std::shared_ptr<Flash> targetFlash = std::make_shared<Flash>();
    std::shared_ptr<SPIFlashHandlerDATABASE> targetSPIFlashHandlerDATABASE = std::make_shared<SPIFlashHandlerDATABASE>();
    targetSPIFlashHandlerDATABASE->flash = targetFlash;
    return targetSPIFlashHandlerDATABASE;
}

void SPIFlashHandlerDATABASE::begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq)
{
    flash->begin(targetSPI.get(), cs, freq);
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