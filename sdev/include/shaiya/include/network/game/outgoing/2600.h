#pragma once
#include <shaiya/include/common.h>

// CUser::PacketPoint

namespace shaiya
{
    #pragma pack(push, 1)
    struct PointBalanceOutgoing
    {
        UINT16 opcode{ 0x2605 };
        UINT32 points;

        PointBalanceOutgoing() = default;

        PointBalanceOutgoing(UINT32 points)
            : points(points)
        {
        }
    };
    #pragma pack(pop)
}
