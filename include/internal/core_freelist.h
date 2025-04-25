#ifndef CORE_FREELIST_H
#define CORE_FREELIST_H 
#include "object.h"
#include "core_freelist_state.h" 
#include "core_runtime.h"

extern _RuntimeState _Runtime ;

static inline _Freelists*
_freelist_GET(void) {
    return &(_Runtime.freelists);
}

#define _FREELIST_SIZE(NAME) (_freelist_GET()->NAME).size  

//maybe i will move it to other file under atomic name 
static inline void 
_atomic_store_ptr (void* region , void* value  ) {
    *(void**)region = value ; 
}

#define _ATOMIC_STORE_PTR(region,new_value)\
    _atomic_store_ptr(&region,new_value)

static inline int 
_FreeList_Push (struct _freelist* fl , void* obj , ssize_t maxsize ) {
    if (fl->size < maxsize && fl->size >=0 ) {
        _ATOMIC_STORE_PTR(*(void** )obj,fl->freelist) ; 
        fl->freelist = obj ; 
        fl->size++;
        return 1;
    }
    return 0;
}

#endif
