#pragma once

#ifndef ROUTER_H
#define ROUTER_H

#include <Arduino.h>
#include "../infrastructure/spicreatehandler.h"
#include "../infrastructure/spiflash_handler.h"
#include "../infrastructure/icm20948_handler.h"
#include "../interfaces/controller/icm20948_controller.h"
#include "../interfaces/database/spiflash_handler.h"
#include "../interfaces/controller/icm20948_controller.h"


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
    ICM20948Controller *icm20948Controller;
};

Router Router1;

uint32_t address = 0;

void setup()
{
    Serial.begin(115200);

    SPICREATEHandler *newSPICREATEHandler = NewSPICreate();

    SPIFlashHandler *newSPIFlashHandlerDATABASE = NewSPIFlashHandlerDATABASE();
    newSPIFlashHandlerDATABASE->begin(newSPICREATEHandler->SPI, flashCS, SPIFREQ);
    uint32_t address = newSPIFlashHandlerDATABASE->setFlashAddress();

    ICM20948Handler *newICM20948HandlerDATABASE = NewICM20948HandlerDATABASE();
    newICM20948HandlerDATABASE->begin(newSPICREATEHandler->SPI, ICMCS, SPIFREQ);
    uint8_t number = newICM20948HandlerDATABASE->WhoAmI();
    if (number != 0x98)
    {
        Serial.println("ICM20948 is not connected.");
    }

    ICM20948Controller *icm20948Controller = NewICM20948Controller(newSPIFlashHandlerDATABASE, newICM20948HandlerDATABASE);

    Router1.icm20948Controller = icm20948Controller;
}

#endif