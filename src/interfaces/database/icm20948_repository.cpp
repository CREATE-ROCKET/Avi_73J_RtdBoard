#include "icm20948_repository.h"

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_handler.h"
#include "../../domain/data.h"

bool ICM20948RepositoryDATABASE::SaveData(uint8_t addr)
{
    int16_t rx[6] = {};
    uint8_t rx_buf[12] = {};
    icm20948Handler->Get(rx, rx_buf);
    spiFlashHandler->write(addr, rx_buf);
    return true;
}

void ICM20948RepositoryDATABASE::GainData(int16_t *rx, uint8_t *rx_buf)
{
    icm20948Handler->Get(rx, rx_buf);
}