#include <stdio.h>
#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"
#include "internal/core_array/core_array_init.h"

extern _RuntimeState _Runtime;
extern Array_Descr* _buildin_descrs[];

_RuntimeState _Runtime = _RuntimeState_INIT(Runtime);

int global_init(void)
{
    printf("[Lifecycle] global_init: starting runtime setup\n");

    if (set_default_types_init() < 0) {
        fprintf(stderr,
                "[Lifecycle][ERROR] set_default_types_init() failed\n");
        return -1;
    }
    printf("[Lifecycle] global_init: default handler set\n");

    // Example for built-in “Int” dtype:
    if (type_init(_buildin_descrs[0], "Int", NULL) < 0) {
        fprintf(stderr,
                "[Lifecycle][ERROR] type_init for \"Int\" failed\n");
        return -1;
    }
    printf("[Lifecycle] global_init: built-in \"Int\" registered\n");

    printf("[Lifecycle] global_init: runtime setup complete\n");
    return 1;
}

