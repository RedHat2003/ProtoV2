#ifndef NDARRAY_ALLOC_H 
#define NDARRAY_ALLOC_H

#include <sys/types.h>


typedef struct {
    void* ctx ; 
    void* (*malloc) (void* ctx , ssize_t size) ; 
    void (*free) (void* ctx , void*ptr , ssize_t size) ; 
}DataMemAlloc;

typedef struct {
    char name[32] ; 
    DataMemAlloc allocator ; 
}DataMem_Handler;

#endif
