#pragma once

namespace util
{
    int detour(void* addr, void* func, size_t size);
    int write_memory(void* addr, void* src, size_t size);
    int write_memory(void* addr, int value, size_t size);
}
