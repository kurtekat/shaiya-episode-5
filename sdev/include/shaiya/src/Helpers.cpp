#include "include/shaiya/include/Helpers.h"
#include "include/shaiya/include/CClientToDBAgent.h"
#include "include/shaiya/include/CUser.h"
#include "include/shaiya/include/SConnection.h"
#include "include/shaiya/include/SConnectionTBaseReconnect.h"
using namespace shaiya;

void Helpers::Send(CUser* user, void* packet, int length)
{
    SConnection::Send(&user->connection.connection, packet, length);
}

void Helpers::SendDBAgent(void* packet, int length)
{
    SConnectionTBaseReconnect::Send(&g_pClientToDBAgent->connection, packet, length);
}
