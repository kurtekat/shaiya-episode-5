#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct GamePointOutgoing
    {
        uint16_t opcode{ 0x2605 };
        uint32_t points;
    };
    #pragma pack(pop)
}
