#pragma once
#include <shaiya/include/common.h>
#include "include/shaiya/include/SConnection.h"

namespace shaiya
{
    #pragma pack(push, 1)
    struct CObjectConnection
    {
        SConnection connection;        //0x00
        PAD(88);
        // 0x128
    };
    #pragma pack(pop)

    static_assert(sizeof(CObjectConnection) == 0x128);
}
