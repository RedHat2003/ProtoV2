#include <stdio.h>
#include <string.h>
#include "internal/core_thread.h"
#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"

static const _RuntimeState initial =  _RuntimeState_INIT(_Runtime) ; 

void 
init_runtime (_RuntimeState* runtime) {
    runtime->main_thread = Thread_get_thread_ident() ;  
    runtime->_initialized = 1 ; 
}

int _RuntimeState_Init (_RuntimeState* runtime) {
    if (runtime->_initialized) {
        memcpy(runtime , &initial , sizeof(*runtime)) ;
        if (runtime->_initialized !=0 ) return -1 ; 

    } 
    init_runtime(runtime) ; 
    printf("[Runtime initalizer] Runtime->main_thread : %lu\n",runtime->main_thread) ; 
    return 1 ;

}
