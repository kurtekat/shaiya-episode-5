#include <util/util.h>
#include <shaiya/include/network/game/incoming/0A00.h>
#include <shaiya/include/network/game/outgoing/0A00.h>
#include "include/main.h"
#include "include/shaiya/CUser.h"
#include "include/shaiya/NetworkHelper.h"
using namespace shaiya;

namespace packet_exchange
{
    /// <summary>
    /// Sends packet 0xA05 to the user.
    /// </summary>
    void send_cancel_0xA05(CUser* user)
    {
        user->exchange.ready = false;

        GameExchangeReadyOutgoing outgoing{};
        outgoing.type = GameExchangeReadyType::Cancel;
        outgoing.canceled = true;
        NetworkHelper::Send(user, &outgoing, sizeof(GameExchangeReadyOutgoing));
    }

    /// <summary>
    /// Sends packet 0xA0A to the users.
    /// </summary>
    void send_cancel_0xA0A(CUser* user, CUser* exchangeUser)
    {
        user->exchange.confirmed = false;

        GameExchangeConfirmOutgoing outgoing{}; 
        outgoing.type = GameExchangeConfirmType::Sender;
        outgoing.confirmed = false;
        NetworkHelper::Send(user, &outgoing, sizeof(GameExchangeConfirmOutgoing));

        outgoing.type = GameExchangeConfirmType::Target;
        NetworkHelper::Send(user, &outgoing, sizeof(GameExchangeConfirmOutgoing));

        exchangeUser->exchange.confirmed = false;
        outgoing.type = GameExchangeConfirmType::Sender;
        NetworkHelper::Send(exchangeUser, &outgoing, sizeof(GameExchangeConfirmOutgoing));

        outgoing.type = GameExchangeConfirmType::Target;
        NetworkHelper::Send(exchangeUser, &outgoing, sizeof(GameExchangeConfirmOutgoing));
    }

    /// <summary>
    /// Sends packets 0xA05 and 0xA0A to the users.
    /// </summary>
    void send_cancel(CUser* user, CUser* exchangeUser)
    {
        send_cancel_0xA05(user);
        send_cancel_0xA05(exchangeUser);
        send_cancel_0xA0A(user, exchangeUser);
    }

    /// <summary>
    /// Handles incoming 0xA0A packets.
    /// </summary>
    void handler_0xA0A(CUser* user, GameExchangeConfirmIncoming* incoming)
    {
        if (!user->exchange.user)
            return;

        if (incoming->confirmed)
        {
            user->exchange.confirmed = true;

            GameExchangeConfirmOutgoing outgoing{};
            outgoing.type = GameExchangeConfirmType::Sender;
            outgoing.confirmed = true;
            NetworkHelper::Send(user, &outgoing, sizeof(GameExchangeConfirmOutgoing));

            outgoing.type = GameExchangeConfirmType::Target;
            NetworkHelper::Send(user->exchange.user, &outgoing, sizeof(GameExchangeConfirmOutgoing));
        }
        else
        {
            send_cancel(user, user->exchange.user);
        }
    }
}

unsigned u0x47D969 = 0x47D969;
unsigned u0x47E0DA = 0x47E0DA;
void __declspec(naked) naked_0x47D964()
{
    __asm
    {
        add eax,-0xA01
        cmp eax,0x9
        je case_0xA0A
        jmp u0x47D969

        case_0xA0A:
        pushad

        push edi // packet
        push ebx // user
        call packet_exchange::handler_0xA0A
        add esp,0x8

        popad

        jmp u0x47E0DA
    }
}

unsigned u0x47E29D = 0x47E29D;
void __declspec(naked) naked_0x47E26F()
{
    __asm
    {
        pushad

        push esi // exchangeUser
        push ecx // user
        call packet_exchange::send_cancel
        add esp,0x8

        popad

        jmp u0x47E29D
    }
}

unsigned u0x47E250 = 0x47E250;
unsigned u0x47DE0D = 0x47DE0D;
void __declspec(naked) naked_0x47DE08()
{
    __asm
    {
        pushad

        push esi // exchangeUser
        push ebx // user
        call packet_exchange::send_cancel
        add esp,0x8

        popad

        // original
        call u0x47E250
        jmp u0x47DE0D
    }
}

unsigned u0x47DFC5 = 0x47DFC5;
void __declspec(naked) naked_0x47DFC0()
{
    __asm
    {
        pushad

        push esi // exchangeUser
        push ebx // user
        call packet_exchange::send_cancel
        add esp,0x8

        popad

        // original
        call u0x47E250
        jmp u0x47DFC5
    }
}

void hook::packet_exchange()
{
    // CUser::PacketExchange switch
    util::detour((void*)0x47D964, naked_0x47D964, 5);
    // CUser::ExchangeCancelReady
    util::detour((void*)0x47E26F, naked_0x47E26F, 6);
    // CUser::PacketExchange case 0xA06
    util::detour((void*)0x47DE08, naked_0x47DE08, 5);
    // CUser::PacketExchange case 0xA07
    util::detour((void*)0x47DFC0, naked_0x47DFC0, 5);
}
