#ifndef CORE_RUNTIME_H
#define CORE_RUNTIME_H

#include "core_mem.h"
#include "core_freelist_state.h"
#include "core_types.h"

typedef struct {
    _mem_allocators   allocators;
    _Freelists        freelists;

    // One entry: the master types-init function
    TypeInitRegistry  type_init;
} _RuntimeState;



#endif // CORE_RUNTIME_H

