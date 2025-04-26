#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct SVector
    {
        float x;
        float y;
        float z;
    };
    #pragma pack(pop)

    static_assert(sizeof(SVector) == 0xC);
}
