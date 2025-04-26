#pragma once
#include <shaiya/include/common.h>
#include "include/shaiya/include/CExchange.h"
#include "include/shaiya/include/CExchangePvP.h"
#include "include/shaiya/include/CObjectConnection.h"

namespace shaiya
{
    #pragma pack(push, 1)
    struct CUser : CObjectConnection//, UserInfo
    {
        PAD(5272);
        CExchange exchange;            //0x15C0
        CExchangePvP exchangePvP;      //0x15E8
        PAD(16888);
        // UserUID
        uint32_t billingId;            //0x582C
        PAD(656);
        uint32_t points;               //0x5AC0
        volatile unsigned pointsLock;  //0x5AC4
        PAD(2008);
        // 0x62A0
    };
    #pragma pack(pop)

    static_assert(sizeof(CUser) == 0x62A0);
}
