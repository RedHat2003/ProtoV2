#include <stdlib.h>

#include "internal/core_mem.h"
#include "internal/core_runtime.h"
void *
_Mem_RawMalloc(ssize_t size)
{
    /* PyMem_RawMalloc(0) means malloc(1). Some systems would return NULL
       for malloc(0), which would be treated as an error. Some platforms would
       return a pointer with no memory behind it, which would break pymalloc.
       To solve these problems, allocate an extra byte. */
    if (size == 0)
        size = 1;
    return malloc(size);
}

void
_Mem_RawFree (void* ptr) {
    free(ptr) ; 
}

extern _RuntimeState _Runtime ;
#define _Object _Runtime.allocators.standard.obj
#define _Mem _Runtime.allocators.standard.mem


/***********************/
/* the "obj" allocator */
/***********************/

void* 
Object_Malloc (ssize_t size) {
    return _Object.malloc(size);
}

void
Object_Free (void* ptr){
    _Object.free (ptr) ; 
}


/***********************/
/* the "mem" allocator */
/***********************/
void* 
Mem_Malloc (ssize_t size) {
    return _Mem.malloc(size) ; 
}

void 
Mem_Free (void* ptr ) {
    _Mem.free (ptr) ; 
}


