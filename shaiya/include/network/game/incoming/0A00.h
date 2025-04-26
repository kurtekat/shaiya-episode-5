#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct GameExchangeConfirmIncoming
    {
        uint16_t opcode{ 0xA0A };
        bool confirmed;
    };
    #pragma pack(pop)
}
