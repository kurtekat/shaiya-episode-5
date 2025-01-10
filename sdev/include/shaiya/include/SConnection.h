#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct SConnection
    {
        PAD(208);
        // 0xD0

        static void Send(SConnection* connection/*ecx*/, void* packet, int length);
    };
    #pragma pack(pop)

    static_assert(sizeof(SConnection) == 0xD0);
}
