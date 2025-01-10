#include <util/util.h>
#include "include/main.h"

unsigned u0x56B898 = 0x56B898;
void __declspec(naked) naked_0x56B87F()
{
    __asm
    {
        // CPlayerData->charId
        mov edi,dword ptr ds:[0x8666D8]
        // CCharacter->id
        cmp edi,[esi+0x34]
        jne wrong_appearance

        // sex, size, face, hair
        mov byte ptr ds:[0x868D94],al
        mov byte ptr ds:[0x867D91],cl
        mov byte ptr ds:[0x867D90],dl
        mov byte ptr ds:[0x867D8F],bl

        wrong_appearance:
        mov ecx,esi
        jmp u0x56B898
    }
}

void hook::packet()
{
    // appearance/sex change bug
    util::detour((void*)0x56B87F, naked_0x56B87F, 6);
}
