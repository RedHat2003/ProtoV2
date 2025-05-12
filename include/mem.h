#ifndef MEM_H 
#define MEM_H 
#include <sys/types.h>

void* Object_Malloc (ssize_t ) ; 
void Object_Free (void* ) ; 



void* Mem_Malloc (ssize_t ) ; 
void Mem_Free (void* ) ; 

#endif
