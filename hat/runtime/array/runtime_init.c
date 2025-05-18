#include <stdio.h>
#include "clinic/ndarrayobj.h"
#include "internal/core_runtime.h"
#include "clinic/array_api.h"
#include "internal/core_array/core_array_init.h"
#include "internal/core_runtime_init.h"

extern Array_Descr* _buildin_descrs[];

int set_default_types_init(void)
{
    printf("[RuntimeInit] Installing default_types_init handler...\n");
    _Runtime.arraysubsys.type_init.init_func = default_types_init;
    if (!_Runtime.arraysubsys.type_init.init_func) {
        fprintf(stderr,
                "[RuntimeInit][ERROR] could not install default_types_init\n");
        return -1;
    }
    printf("[RuntimeInit] default_types_init handler installed successfully\n");
    return 1;
}

int type_init(Array_Descr* descr,
              char* name,
              TypeObject* dtype_super_class)
{
    printf("[RuntimeInit] type_init: registering \"%s\"...\n", name);
    int err = _Runtime.arraysubsys.type_init.init_func(
                  descr, name, dtype_super_class);
    if (err == 0) {
        printf("[RuntimeInit] type_init: \"%s\" registered OK\n", name);
        return 1;
    }
    else {
        fprintf(stderr,
                "[RuntimeInit][ERROR] type_init failed for \"%s\"\n", name);
        return -1;
    }
}

