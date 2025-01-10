#pragma once
#include <shaiya/include/common.h>

// CUser::PacketExchange

namespace shaiya
{
    #pragma pack(push, 1)
    struct ExchangeConfirmIncoming
    {
        UINT16 opcode{ 0xA0A };
        bool confirmed;
    };
    #pragma pack(pop)
}
