#pragma onceASE

#ifndef ICM20948_HANDLER_H
#define ICM20948_HANDLER_H

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/icm20948_handler.h"
#include <ICM20948.h>
#include <memory>

// class ICM20948HandlerDATABASE : public ICM20948Handler
// {
// public:
//     ICM *icm20948;
//     void begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq = 8000000) override;
//     uint8_t WhoAmI() override;
//     void Get(int16_t *rx, uint8_t *rx_buf) override;
// };

// ICM20948HandlerDATABASE *NewICM20948HandlerDATABASE()
// {
//     ICM *targetICM20948 = new ICM();
//     ICM20948HandlerDATABASE *targetICM20948HandlerDATABASE = new ICM20948HandlerDATABASE();
//     targetICM20948HandlerDATABASE->icm20948 = targetICM20948;
//     return targetICM20948HandlerDATABASE;
// }

class ICM20948HandlerDATABASE : public ICM20948Handler
{
public:
    ICM *icm20948;
    void begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq = 8000000) override;
    uint8_t WhoAmI() override;
    void Get(int16_t *rx, uint8_t *rx_buf) override;
};

std::shared_ptr<ICM20948HandlerDATABASE> NewICM20948HandlerDATABASE()
{
    std::shared_ptr<ICM> targetICM20948 = std::make_shared<ICM>();
    std::shared_ptr<ICM20948HandlerDATABASE> targetICM20948HandlerDATABASE = std::make_shared<ICM20948HandlerDATABASE>();
    targetICM20948HandlerDATABASE->icm20948 = targetICM20948.get();
    return targetICM20948HandlerDATABASE;
}

void ICM20948HandlerDATABASE::begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq)
{
    icm20948->begin(targetSPI.get(), cs, freq);
}

uint8_t ICM20948HandlerDATABASE::WhoAmI()
{
    return icm20948->WhoAmI();
}

void ICM20948HandlerDATABASE::Get(int16_t *rx, uint8_t *rx_buf)
{
    icm20948->Get(rx, rx_buf);
}

#endif
