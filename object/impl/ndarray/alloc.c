#include "object.h"
#include <stdlib.h>
#include "clinic/capsule.h"
#include "internal/core_runtime.h"

extern _RuntimeState _Runtime ; 


void* 
_alloc(size_t nelem, size_t esz) {
    return _Runtime.arraysubsys.default_handler.allocator.malloc(NULL ,nelem * esz) ; 
}

void 
_free(void* ptr) {
    _Runtime.arraysubsys.default_handler.allocator.free(NULL, ptr);
}


void* 
dim_alloc(size_t sz) {
    if (sz <2 ) {
        sz =2 ; 
    }
    return _alloc(sz , sizeof(size_t));
}

static inline DataMem_Handler* 
current_handler_get() {
    _RuntimeState* cruntime = &_Runtime ; 
    _ArraySubSys* arrsys  = arraysubsys_get(cruntime) ; 
    return &arrsys->default_handler ; 
}

char* 
currnet_handler_name(void){
    DataMem_Handler* chandler = current_handler_get() ; 
    return chandler->name;
}




