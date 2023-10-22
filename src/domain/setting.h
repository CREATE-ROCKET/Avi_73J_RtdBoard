#pragma once

#ifndef SETTING_H
#define SETTING_H

#include <NEC920.hpp>
#include <mutex>

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
#define SPIFREQ 5000000

SPICREATE::SPICreate SPIC1;
SPICREATE::SPICreate SPIC2;

uint8_t GroundMode = 0;
uint8_t GimbalMode = 0;

uint8_t Send_Data[256] = {};

std::mutex sendDataMutex;

#endif
