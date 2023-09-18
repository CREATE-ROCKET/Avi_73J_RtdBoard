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
    std::shared_ptr<ICM20948Controller> icm20948Controller;
    std::shared_ptr<LPS25Controller> lps25Controller;
};

Router Router1;

uint32_t address = 0;

void setup()
{
    Serial.begin(115200);

    // SPICREATE
    std::shared_ptr<SPICREATEHandlerDATABASE> newSPICREATEHandlerDATABASE = NewSPICreate();
    newSPICREATEHandlerDATABASE->begin(VSPI, SCK1, MISO1, MOSI1, SPIFREQ);

    // SPIFLASH
    std::shared_ptr<SPIFlashHandlerDATABASE> newSPIFlashHandlerDATABASE = NewSPIFlashHandlerDATABASE();
    newSPIFlashHandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, flashCS, SPIFREQ);
    // newSPIFlashHandlerDATABASE->erase();
    uint32_t address = newSPIFlashHandlerDATABASE->setFlashAddress();

    // ICM20948
    std::shared_ptr<ICM20948HandlerDATABASE> newICM20948HandlerDATABASE = NewICM20948HandlerDATABASE();
    newICM20948HandlerDATABASE->begin(newSPICREATEHandlerDATABASE->SPI, ICMCS, SPIFREQ);
    uint8_t number = newICM20948HandlerDATABASE->WhoAmI();
    if (number != 0x98)
    {
        Serial.println("ICM20948 is not connected.");
        Serial.println(number);
    }

    // LPS25
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
    std::shared_ptr<ICM20948Controller> icm20948Controller = NewICM20948Controller(newSPIFlashHandlerDATABASE, newICM20948HandlerDATABASE);
    Router1.icm20948Controller = icm20948Controller;

    // LPS25 Controller
    std::shared_ptr<LPS25Controller> lps25Controller = NewLPS25Controller(newSPIFlashHandlerDATABASE, newLPS25HandlerDATABASE);
    Router1.lps25Controller = lps25Controller;
    
    // delay(3000);
    Serial.println("Address: " + String(address));
    // int16_t rx[6] = {};
    uint8_t rx_buf[256] = {};
    // for (int i = 0; i < 256; i++)
    // {
    //     rx_buf[i] = i;
    // }
    // newSPIFlashHandlerDATABASE->write(address, rx_buf);
    // address += 256;
    delay(10);
    for (uint32_t ad = 0; ad < address; ad += 256)
    {
        newSPIFlashHandlerDATABASE->read(ad, rx_buf);
        for (int i = 0; i < 256; i++)
        {
            Serial.print(rx_buf[i]);
            Serial.print(" ");
        }
        Serial.println();
        delay(100);
    }

}

#endif