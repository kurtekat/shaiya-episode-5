#pragma once
#include <shaiya/include/common.h>

// CUser::PacketExchange

namespace shaiya
{
    enum struct ExchangeReadyType : UINT8
    {
        Sender = 1,
        Target,
        Cancel
    };

    #pragma pack(push, 1)
    struct ExchangeReadyOutgoing
    {
        UINT16 opcode{ 0xA05 };
        ExchangeReadyType type;
        bool canceled;

        ExchangeReadyOutgoing() = default;

        ExchangeReadyOutgoing(ExchangeReadyType type, bool canceled)
            : type(type), canceled(canceled)
        {
        }
    };
    #pragma pack(pop)

    enum struct ExchangeConfirmType : UINT8
    {
        Sender = 1,
        Target,
        Cancel
    };

    #pragma pack(push, 1)
    struct ExchangeConfirmOutgoing
    {
        UINT16 opcode{ 0xA0A };
        ExchangeConfirmType type;
        bool confirmed;

        ExchangeConfirmOutgoing() = default;

        ExchangeConfirmOutgoing(ExchangeConfirmType type, bool confirmed)
            : type(type), confirmed(confirmed)
        {
        }
    };
    #pragma pack(pop)
}
