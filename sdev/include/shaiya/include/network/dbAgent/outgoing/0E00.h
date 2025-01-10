#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct DBAgentPointReloadOutgoing
    {
        UINT16 opcode{ 0xE06 };
        ULONG userId;
        UINT32 points;
    };
    #pragma pack(pop)
}
