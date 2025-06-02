#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "clinic/capsule.h"
#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"
#include "internal/core_array/core_handler.h"


 
void* 
default_malloc(void* ctx , ssize_t size ) {
    (void )ctx ; 
    return malloc(size );
}

void 
default_free (void* ctx , void* ptr){
    (void )ctx ; 
    free(ptr) ;
}


#define _ALLOC _Runtime.arraysubsys.current_handler.allocator  

void* 
_alloc(size_t nelem, size_t esz) {
    return _ALLOC.malloc(NULL ,nelem * esz) ; 
}

void 
_free(void* ptr) {
    _ALLOC.free(NULL, ptr);
}


void* 
dim_alloc(size_t sz) {
    if (sz <2 ) {
        sz =2 ; 
    }
    return _alloc(sz , sizeof(size_t));
}




Object* current_handler ; 

static inline DataMem_Handler* 
arrsys_handler_get(void) {
    _RuntimeState* cruntime = &_Runtime ; 
    _ArraySubSys* arrsys  = arraysubsys_get(cruntime) ; 
    return &arrsys->current_handler ; 
}


char* 
currnet_handler_name(void){
    DataMem_Handler* handler = ((DataMem_Handler*)
                                Capsule_GetPointer(current_handler)) ; 
    return handler->name; 
}




int 
default_handler_init () {
    DataMem_Handler* arrsys_current_handler = arrsys_handler_get() ; 

    current_handler = Capsule_New(arrsys_current_handler , "currnet_mem_handler") ; 
    
    if (current_handler== NULL ) {
        return -1;
    }
    return 1;
}

void* 
DataMem_UserNEW(ssize_t size, Object* mem_handler) {
    DataMem_Handler* handler = (DataMem_Handler*)Capsule_GetPointer(mem_handler);
    if (handler == NULL) {
        return NULL;
    }

    void* result = handler->allocator.malloc(NULL, size);
    if (result == NULL) {
        return NULL;
    }

    printf("current_handler successfully allocated %zu bytes\n", size);
    return result;
}


