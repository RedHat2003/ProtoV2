#ifndef CORE_OBMALLOC_H  
#define CORE_OBMALLOC_H 

#include "core_mem_init.h"
#include "core_runtime_init.h"



void* Object_Malloc (ssize_t) ; 

void* 
_Object_MallocWithType (TypeObject* tp , ssize_t size) {
    void* mem = Object_Malloc(size) ; 
    return mem;
}

#endif 
