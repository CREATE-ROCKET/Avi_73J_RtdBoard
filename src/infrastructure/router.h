#pragma once

#ifndef ROUTER_H
#define ROUTER_H

#include <Arduino.h>
#include "../infrastructure/spicreatehandler.h"
#include "../infrastructure/spiflash_handler.h"
#include "../infrastructure/icm20948_handler.h"
#include "../infrastructure/lps25_handler.h"
#include "../interfaces/controller/icm20948_controller.h"
#include "../interfaces/database/spiflash_handler.h"
#include "../interfaces/controller/lps25_controller.h"

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
    LPS25Controller *lps25Controller;
};

Router Router1;

uint32_t address = 0;

void setup()
{
    Serial.begin(115200);

    // // SPICREATE
    // SPICREATEHandlerDATABASE *newSPICREATEHandlerDATABASE = NewSPICreate();
    // newSPICREATEHandlerDATABASE->begin(VSPI, SCK1, MISO1, MOSI1, SPIFREQ);

    std::shared_ptr<SPICREATEHandlerDATABASE> newSPICREATEHandlerDATABASE = NewSPICreate();
    newSPICREATEHandlerDATABASE->begin(VSPI, SCK1, MISO1, MOSI1, SPIFREQ);

    // // SPIFLASH
    SPIFlashHandlerDATABASE *newSPIFlashHandlerDATABASE = NewSPIFlashHandlerDATABASE();
    newSPIFlashHandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, flashCS, SPIFREQ);
    // newSPIFlashHandlerDATABASE->erase();
    uint32_t address = newSPIFlashHandlerDATABASE->setFlashAddress();

    std::shared_ptr<SPIFlashHandlerDATABASE> newSPIFlashHandlerDATABASE = NewSPIFlashHandlerDATABASE();
    newSPIFlashHandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, flashCS, SPIFREQ);
    // newSPIFlashHandlerDATABASE->erase();
    uint32_t address = newSPIFlashHandlerDATABASE->setFlashAddress();

    // // ICM20948
    // ICM20948HandlerDATABASE *newICM20948HandlerDATABASE = NewICM20948HandlerDATABASE();
    // newICM20948HandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, ICMCS, SPIFREQ);
    // uint8_t number = newICM20948HandlerDATABASE->WhoAmI();
    // if (number != 0x98)
    // {
    //     Serial.println("ICM20948 is not connected.");
    //     Serial.println(number);
    // }

    std::shared_ptr<ICM20948HandlerDATABASE> newICM20948HandlerDATABASE = NewICM20948HandlerDATABASE();
    newICM20948HandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, ICMCS, SPIFREQ);
    uint8_t number = newICM20948HandlerDATABASE->WhoAmI();
    if (number != 0x98)
    {
        Serial.println("ICM20948 is not connected.");
        Serial.println(number);
    }

    // // LPS25
    // LPS25HandlerDATABASE *newLPS25HandlerDATABASE = NewLPS25HandlerDATABASE();
    // newLPS25HandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, LPSCS, SPIFREQ);
    // uint8_t number2 = newLPS25HandlerDATABASE->WhoAmI();
    // if (number2 != 0xBD)
    // {
    //     Serial.println("LPS25 is not connected.");
    //     Serial.println(number2);
    // }

    std::shared_ptr<LPS25HandlerDATABASE> newLPS25HandlerDATABASE = NewLPS25HandlerDATABASE();
    newLPS25HandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, LPSCS, SPIFREQ);
    uint8_t number2 = newLPS25HandlerDATABASE->WhoAmI();
    if (number2 != 0xBD)
    {
        Serial.println("LPS25 is not connected.");
        Serial.println(number2);
    }

    // Controller Initialization
    // ICM20948 Controller
    ICM20948Controller *icm20948Controller = NewICM20948Controller(newSPIFlashHandlerDATABASE, newICM20948HandlerDATABASE);
    Router1.icm20948Controller = icm20948Controller;

    // LPS25 Controller
    LPS25Controller *lps25Controller = NewLPS25Controller(newSPIFlashHandlerDATABASE, newLPS25HandlerDATABASE);
    Router1.lps25Controller = lps25Controller;
}

#endif