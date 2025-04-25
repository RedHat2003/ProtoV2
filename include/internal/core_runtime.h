#ifndef CORE_RUNTIME_H 
#define CORE_RUNTIME_H

#include "core_mem.h"
#include "core_freelist_state.h"

typedef struct runtimestate {
    _mem_allocators allocators ;     
    _Freelists Freelists ; 
}_RuntimeState ; 



#endif 
