#include "icm20948_controller.h"

#include "../../domain/data.h"

#include "../../usecase/icm20948_interactor.h"
#include "../../usecase/icm20948_repository_usecase.h"

#include "../../interfaces/database/spiflash_handler.h"
#include "../../interfaces/database/icm20948_repository.h"

std::shared_ptr<ICM20948Controller> NewICM20948Controller(std::shared_ptr<SPIFlashHandler> spiflashHandler, std::shared_ptr<ICM20948Handler> icm20948Handler)
{
    std::shared_ptr<ICM20948RepositoryDATABASE> icm20948Repository = std::make_shared<ICM20948RepositoryDATABASE>(spiflashHandler, icm20948Handler);
    std::shared_ptr<ICM20948Interactor> icm20948Interactor = std::make_shared<ICM20948Interactor>(icm20948Repository);
    return std::make_shared<ICM20948Controller>(icm20948Interactor);
}

bool ICM20948Controller::Add(uint8_t addr)
{
    return icm20948Interactor->AddData(addr);
}

Data ICM20948Controller::Get(int16_t *rx, uint8_t *rx_buf)
{
    icm20948Interactor->GetData(rx, rx_buf);
    Data result;
    result.accel[0] = rx_buf[0];
    result.accel[1] = rx_buf[1];
    result.accel[2] = rx_buf[2];
    return result;
}