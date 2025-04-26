#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    enum struct GameExchangeReadyType : uint8_t
    {
        Sender = 1,
        Target,
        Cancel
    };

    #pragma pack(push, 1)
    // TP_EXC_READY
    struct GameExchangeReadyOutgoing
    {
        uint16_t opcode{ 0xA05 };
        GameExchangeReadyType type;
        bool canceled;
    };
    #pragma pack(pop)

    enum struct GameExchangeConfirmType : uint8_t
    {
        Sender = 1,
        Target,
        Cancel
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
