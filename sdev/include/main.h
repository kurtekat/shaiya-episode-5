#pragma once

void Main();
extern "C" __declspec(dllexport) void DllExport();

namespace hook
{
    void packet_exchange();
    void packet_shop();
}
