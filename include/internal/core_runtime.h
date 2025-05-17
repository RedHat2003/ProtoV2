#ifndef CORE_RUNTIME_H
#define CORE_RUNTIME_H

#include "core_mem.h"
#include "core_freelist_state.h"
#include "core_array/core_array_state.h"


typedef struct {
    _mem_allocators   allocators;
    _Freelists        freelists;
    
    _ArraySubSys      arraysubsys ; 

} _RuntimeState;



#endif // CORE_RUNTIME_H

