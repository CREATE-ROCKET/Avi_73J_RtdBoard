#include "lps25_repository.h"

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/lps25_handler.h"
#include "../../domain/data.h"

bool LPS25RepositoryDATABASE::SaveData(uint8_t addr)
{
    uint8_t rx[3] = {};
    lps25Handler->Get(rx);
    spiFlashHandler->write(addr, rx);
    return true;
}

void LPS25RepositoryDATABASE::GainData(uint8_t *rx)
{
    lps25Handler->Get(rx);
}