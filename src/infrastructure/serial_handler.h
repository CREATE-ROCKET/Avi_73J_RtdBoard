

#pragma once

#ifndef Serial_HANDLER_H
#define Serial_HANDLER_H

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/lps25_handler.h"
#include <Arduino.h>

// To do

class SerialHandlerDATABASE : public SerialHandler
{
public:
    void begin(unsigned long baud, uint32_t config = 134217756U, int8_t rxPin = (int8_t)(-1), int8_t txPin = (int8_t)(-1), bool invert = false, unsigned long timeout_ms = 20000UL, uint8_t rxfifo_full_thrhd = (uint8_t)112U) override;
};

#endif
