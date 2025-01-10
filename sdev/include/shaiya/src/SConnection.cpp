#include "include/shaiya/include/SConnection.h"
using namespace shaiya;

void SConnection::Send(SConnection* connection/*ecx*/, void* packet, int length)
{
    typedef void(__thiscall* LPFN)(SConnection*, void*, int);
    (*(LPFN)0x4ED0E0)(connection, packet, length);
}
