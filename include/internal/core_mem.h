#ifndef CORE_MEM_H
#define CORE_MEM_H

#include <stdlib.h>
#include <sys/types.h>

extern void* _Mem_RawMalloc (ssize_t size) ; 
extern void  _Mem_RawFree (void* ptr) ; 

typedef struct {
    void* (*malloc) (ssize_t size) ; 
    void  (*free) (void* ptr) ; 
}_MemAllocEx;

typedef struct {
    
    struct {
        _MemAllocEx raw ;
        _MemAllocEx mem ;
        _MemAllocEx obj ;
    }standard;

}_mem_allocators;

#endif 

