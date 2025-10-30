#include <util/util.h>
#include "include/main.h"

void hook::patch()
{
    // speed recreation
    util::write_memory((void*)0x4AE1A4, 0x90, 29);
    util::write_memory((void*)0x4AE1C3, 0x90, 25);
    util::write_memory((void*)0x4AE1E4, 0x90, 6);
    // speed enchant
    util::write_memory((void*)0x4E241A, 0x02, 1);
    util::write_memory((void*)0x4E241C, 0x02, 1);
    util::write_memory((void*)0x4E244B, 0x02, 1);
    util::write_memory((void*)0x4E244D, 0x02, 1);
    util::write_memory((void*)0x4E245E, 0x03, 1);
    util::write_memory((void*)0x4E2467, 0x03, 1);
}
