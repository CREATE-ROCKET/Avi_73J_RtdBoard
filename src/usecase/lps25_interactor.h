#pragma once

#ifndef LPS25_INTERACTOR_H
#define LPS25_INTERACTOR_H

#include "../domain/data.h"
#include "../usecase/lps25_repository_usecase.h"

class LPS25Interactor
{
private:
    std::shared_ptr<LPS25Repository> lps25Repository;

public:
    LPS25Interactor(std::shared_ptr<LPS25Repository> lps25Repository) : lps25Repository(lps25Repository) {}

    bool AddData(uint8_t addr);
    void GetData(uint8_t *rx);
};

bool LPS25Interactor::AddData(uint8_t addr)
{
    return lps25Repository->SaveData(addr);
}

void LPS25Interactor::GetData(uint8_t *rx)
{
    lps25Repository->GainData(rx);
}

#endif
