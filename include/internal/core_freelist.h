#ifndef CORE_FREELIST_H
#define CORE_FREELIST_H 
#include "object.h"
#include "core_freelist_state.h" 
#include "core_runtime.h"

extern _RuntimeState _Runtime ;

inline _Freelists* 
_freelist_GET (void) { 
    return &(_Runtime.freelists);
}

    
#endif
