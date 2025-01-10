#pragma once
#include <shaiya/include/common.h>
#include "include/shaiya/include/CExchange.h"
#include "include/shaiya/include/CObject.h"

namespace shaiya
{
    #pragma pack(push, 1)
    struct CUser
    {
        CObjectConnection connection;   //0x00
        PAD(5272);
        CExchange exchange;             //0x15C0
        CExchangePvP exchangePvP;       //0x15E8
        PAD(16888);
        // UserUID
        ULONG userId;                   //0x582C
        PAD(656);
        UINT32 points;                  //0x5AC0
        volatile unsigned disableShop;  //0x5AC4
        PAD(2008);
        // 0x62A0
    };
    #pragma pack(pop)

    static_assert(sizeof(CUser) == 0x62A0);
}
