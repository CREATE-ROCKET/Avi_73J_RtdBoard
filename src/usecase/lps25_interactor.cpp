#include "lps25_interactor.h"

#include "../domain/data.h"
#include "../usecase/lps25_repository_usecase.h"

bool LPS25Interactor::AddData(uint8_t addr)
{
    return lps25Repository->SaveData(addr);
}

void LPS25Interactor::GetData(uint8_t *rx)
{
    lps25Repository->GainData(rx);
}