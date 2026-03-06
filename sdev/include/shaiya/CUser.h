#pragma once
#include <shaiya/include/common.h>
#include "CExchange.h"
#include "CExchangePvP.h"
#include "CObjectConnection.h"
#include "MyShop.h"

namespace shaiya
{
    enum struct UserPvPStatus : int32_t
    {
        None,
        RequestSent,
        RequestRecv,
        Countdown,
        Start,
        Exchange
    };

    #pragma pack(push, 1)
    struct CUser : CObjectConnection//, UserInfo
    {
        PAD(5272);
        CExchange exchange;            //0x15C0
        CExchangePvP exchangePvP;      //0x15E8
        MyShop myShop;                 //0x1634
        // 0x17F4
        PAD(15768);
        UserPvPStatus pvpStatus;       //0x558C
        PAD(668);
        // UserUID
        uint32_t billingId;            //0x582C
        PAD(656);
        uint32_t points;               //0x5AC0
        volatile unsigned pointsLock;  //0x5AC4
        PAD(2008);
        // 0x62A0

        static void ExchangeCancelReady(CUser* user/*ecx*/, CUser* exchangeUser/*esi*/);
    };
    #pragma pack(pop)

    static_assert(sizeof(CUser) == 0x62A0);
}
