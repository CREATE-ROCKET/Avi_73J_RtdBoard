#include "lps25_handler.h"

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/icm20948_handler.h"

std::shared_ptr<LPS25HandlerDATABASE> NewLPS25HandlerDATABASE()
{
    std::shared_ptr<LPS> targetLPS25 = std::make_shared<LPS>();
    std::shared_ptr<LPS25HandlerDATABASE> targetLPS25HandlerDATABASE = std::make_shared<LPS25HandlerDATABASE>();
    targetLPS25HandlerDATABASE->lps25 = targetLPS25;
    return targetLPS25HandlerDATABASE;
}

void LPS25HandlerDATABASE::begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq)
{
    lps25->begin(targetSPI.get(), cs, freq);
}

uint8_t LPS25HandlerDATABASE::WhoAmI()
{
    return lps25->WhoAmI();
}

void LPS25HandlerDATABASE::Get(uint8_t *rx)
{
    lps25->Get(rx);
}