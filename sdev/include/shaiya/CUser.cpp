#include "CUser.h"
using namespace shaiya;

void CUser::ExchangeCancelReady(CUser* user/*ecx*/, CUser* exchangeUser/*esi*/)
{
    unsigned u0x47E250 = 0x47E250;

    __asm
    {
        mov esi,exchangeUser
        mov ecx,user
        call u0x47E250
    }
}
