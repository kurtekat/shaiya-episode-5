#pragma once

namespace shaiya
{
    struct CUser;

    struct Helpers
    {
        static void Send(CUser* user, void* packet, int length);
        static void SendDBAgent(void* packet, int length);
    };
}
