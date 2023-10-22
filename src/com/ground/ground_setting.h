#pragma once

#ifndef Ground_Setting
#define Ground_Setting

#include <Arduino.h>

#include <NEC920.hpp>

const int pin920Rx = 18;
const int pin920Tx = 19;
const int pin920Reset = 21;
const int pin920Wakeup = 22;
const int pin920Mode = 23;

NEC920 nec920;
bool isNec920Setup = false;

#endif
