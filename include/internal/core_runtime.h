#ifndef CORE_RUNTIME_H
#define CORE_RUNTIME_H

#include "core_mem.h"
#include "core_freelist_state.h"
#include "core_array/core_array_state.h"


typedef struct {
    _mem_allocators   allocators;
    _Freelists        freelists;
    
    _ArraySubSys      arraysubsys ; 

    int _initialized ; 

    unsigned long main_thread;

} _RuntimeState;




static inline _ArraySubSys* 
arraysubsys_get(_RuntimeState* runtime) {
    return &runtime->arraysubsys;
}

static inline unsigned long 
runtime_get_thread_ident (_RuntimeState* runtime){
    return runtime->main_thread ; 
}

void _Is_Initialized() ; 
int _RuntimeState_Init(_RuntimeState* runtime) ; 



#endif // CORE_RUNTIME_H

