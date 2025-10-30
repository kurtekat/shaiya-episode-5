#include <util/util.h>
#include "include/main.h"
#include "include/shaiya/CUser.h"
using namespace shaiya;

void user_hook(CUser* user)
{
    user->exchange.confirmed = false;
}

unsigned u0x45516B = 0x45516B;
void __declspec(naked) naked_0x455165()
{
    __asm
    {
        pushad

        push edi // user
        call user_hook
        add esp,0x4

        popad

        // original
        mov [edi+0x6264],ebx
        jmp u0x45516B
    }
}

unsigned u0x455A89 = 0x455A89;
void __declspec(naked) naked_0x455A83()
{
    __asm
    {
        pushad
 
        push edi // user
        call user_hook
        add esp,0x4

        popad

        // original
        mov [edi+0x58EC],ebx
        jmp u0x455A89
    }
}

void Main()
{
    // CUser::CUser
    util::detour((void*)0x455165, naked_0x455165, 6);
    // CUser::ResetCharacter
    util::detour((void*)0x455A83, naked_0x455A83, 6);

    hook::packet_exchange();
    hook::packet_shop();
}
