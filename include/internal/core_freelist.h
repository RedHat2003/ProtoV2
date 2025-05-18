#ifndef CORE_FREELIST_H
#define CORE_FREELIST_H 
#include "object.h"
#include "core_runtime.h"
#include "core_freelist_state.h" 
#include "internal/core_runtime_init.h"


static inline _Freelists*
_freelists_GET(void) {
    return &(_Runtime.freelists);
}

#define _FREELIST_GET(NAME)     \
    _freelists_GET()->NAME

#define _FREELIST_SIZE(NAME)    \
    _freelists_GET()->NAME.size

#define _FREELIST_PUSH(NAME, op, limit)     \
    _freelist_push(&_freelists_GET()->NAME, (void* )op, limit)

#define _FREELIST_POP(TYPE, NAME) \
    _CAST(TYPE*, _FreeList_Pop(&_freelists_GET()->NAME))
//maybe i will move it to other file under atomic name 
static inline void 
_atomic_store_ptr (void* region , void* value  ) {
    *(void**)region = value ; 
}

#define _ATOMIC_STORE_PTR(region,new_value)\
    _atomic_store_ptr(&region,new_value)

static inline int 
_freelist_push(struct _freelist* fl , void* obj , ssize_t maxsize ) {
    if (fl->size < maxsize && fl->size >=0 ) {
        _ATOMIC_STORE_PTR(*(void** )obj,fl->freelist) ; 
        fl->freelist = obj ; 
        fl->size++;
        return 1;
    }
    return 0;
}

static inline void*
_FreeList_PopNoStats(struct _freelist* fl) {
    void* obj = fl->freelist ; 

    if (obj!=NULL){
        fl->freelist = *(void** )obj;
        fl->size-- ; 
    }
    return obj;
}

static inline Object *
_FreeList_Pop(struct _freelist* fl)
{
    Object *op = _FreeList_PopNoStats(fl);
    if (op != NULL) {
        op->ref_cnt= 1 ; 
    }
    return op;
}

#endif
