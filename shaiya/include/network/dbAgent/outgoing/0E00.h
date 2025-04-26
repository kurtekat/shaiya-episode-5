#pragma once
#include <shaiya/include/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    // TP_DB_POINT_RELOAD
    struct DBAgentPointReloadOutgoing
    {
        uint16_t opcode{ 0xE06 };
        uint32_t billingId;
        uint32_t points;
    };
    #pragma pack(pop)
}
