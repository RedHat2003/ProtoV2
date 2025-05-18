#ifndef NDARRAY_ALLOC_H 
#define NDARRAY_ALLOC_H

#include <stdlib.h>
#include <sys/types.h>
#include "clinic/ndarray/_src/handler.h"

static inline void* 
default_malloc(void* ctx , ssize_t size ) {
    (void )ctx ; 
    return malloc(size );
}
static inline void 
default_free (void* ctx , void* ptr){
    (void )ctx ; 
    free(ptr) ;
}

typedef struct {
    void* ctx ; 
    void* (*malloc) (void* ctx , ssize_t size) ; 
    void (*free) (void* ctx , void*ptr) ; 
}DataMemAlloc;

typedef struct {
    char name[32] ; 
    DataMemAlloc allocator ; 
}DataMem_Handler;



#endif

