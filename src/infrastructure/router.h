#pragma once

#ifndef ROUTER_H
#define ROUTER_H

#include <Arduino.h>
#include "spicreatehandler.h"
#include "spiflash_handler.h"
#include "icm20948_handler.h"
#include "../interfaces/controller/Accel_controller.h"
#include "../interfaces/database/spiflash_handler.h"

#define SPIFREQ 5000000

// ピンの定義
#define flashCS 27
#define SCK1 33
#define MISO1 25
#define MOSI1 26
#define SCK2 19
#define MISO2 22
#define MOSI2 23
#define H3LIS331CS 32
#define LPSCS 14
#define ICMCS 13
#define LEDPIN 18

// コマンドの定義
#define COMMANDPREPARATION 'p'
#define COMMANDDELETE 'd'
#define COMMANDSTOP 's'
#define COMMANDLOG 'l'
#define COMMANDFINISHSETUP 'r'
#define COMMANDDELETEDONE 'f'
#define COMMANDRETURN 'j'

class Router
{
public:
    FlashController *flashController;

};

Router Router1;

void setup()
{
    SPICREATEHadndler *newSPICREATEHandler = NewSPICreate();
    SPIFlashHandlerDATABASE *newSPIFlashHandler = NewSPIFlashHandler();
    // ICM20948HandlerDATABASE *newICM20948Handler = NewICM20948Handler();

    newSPIFlashHandler->begin(newSPICREATEHandler->SPI, flashCS, SPIFREQ);
    // newICM20948Handler->begin(newSPICREATEHandler->SPI, ICMCS, SPIFREQ);

    FlashController *flashController = NewFlashController(newSPIFlashHandler);

    Router1.flashController = flashController;
}

#endif