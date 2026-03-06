#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    enum struct GameExchangeConfirmType : uint8_t
    {
        User = 1,
        ExchangeUser
    };

    #pragma pack(push, 1)
    struct GameExchangeConfirmOutgoing
    {
        uint16_t opcode{ 0xA0A };
        GameExchangeConfirmType type;
        bool confirmed;
    };
    #pragma pack(pop)
}
