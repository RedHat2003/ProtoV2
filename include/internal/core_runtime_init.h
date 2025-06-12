#ifndef CORE_RUNTIME_INIT
#define CORE_RUNTIME_INIT

#include "core_mem.h"
#include "core_runtime.h"
#include "core_mem_init.h"
#include "core_array/core_mem_init.h"

#define _RuntimeState_INIT(runtime)                            \
{                                                              \
    .allocators = {                                            \
        .standard = _mem_allocators_standard_INIT(),           \
    },                                                         \
    .freelists = {                                             \
        .tuple_iters = {                                       \
            .freelist = NULL,                                  \
            .size     = 0,                                     \
        },                                                     \
    },                                                         \
    .arraysubsys = {                                           \
        .type_init = { .init_func = NULL },                    \
        .current_handler = _DATAMEM_HANDLER_DEFAULT()          \
    },                                                         \
    ._initialized = 0                                          \
}


extern _RuntimeState _Runtime;

#endif  /* CORE_RUNTIME_INIT */

