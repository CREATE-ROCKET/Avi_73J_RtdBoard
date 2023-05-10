

    #pragma onceASE

#ifndef LPS25_HANDLER_H
#define LPS25_HANDLER_H

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/lps25_handler.h"
#include <LPS25HB.h>

class LPS25HandlerDATABASE : public LPS25Handler
{
public:
    LPS *lps25;
    void begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq = 8000000) override;
    uint8_t WhoAmI() override;
    void Get(uint8_t *rx) override;
};

LPS25HandlerDATABASE *NewLPS25HandlerDATABASE()
{
    LPS *targetLPS25 = new LPS();
    LPS25HandlerDATABASE *targetLPS25HandlerDATABASE = new LPS25HandlerDATABASE();
    targetLPS25HandlerDATABASE->lps25 = targetLPS25;
    return targetLPS25HandlerDATABASE;
}

void LPS25HandlerDATABASE::begin(SPICREATE::SPICreate *targetSPI, int cs, uint32_t freq)
{
    lps25->begin(targetSPI, cs, freq);
}

uint8_t LPS25HandlerDATABASE::WhoAmI()
{
    return lps25->WhoAmI();
}

void LPS25HandlerDATABASE::Get(uint8_t *rx)
{
    lps25->Get(rx);
}

#endif
