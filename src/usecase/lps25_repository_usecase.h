#pragma once

#ifndef LPS25_REPOSITORY_USECASE_H
#define LPS25_REPOSITORY_USECASE_H

#include "../domain/data.h"

class LPS25Repository
{
public:
    virtual bool SaveData(uint8_t addr) = 0;
    virtual void GainData(uint8_t *rx) = 0;
};

#endif