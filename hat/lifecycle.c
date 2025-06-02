#include <stdio.h>
#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"
#include "internal/core_array/core_array_init.h"
#include "clinic/ndarray/_src/handler.h"

extern Array_Descr* _buildin_descrs[];
_RuntimeState _Runtime = _RuntimeState_INIT(&_Runtime);  

static int runtime_initialized = 0 ; 

void _Is_Initialized (){
    if (runtime_initialized){
        printf ("Yes Runtime was initialized !\n");
    }
}



int global_init(void)
{
    printf("[Lifecycle] global_init: starting runtime setup\n");

    if (runtime_initialized) {
        printf ("[Runtime already initialized !\n]") ; 
        return 1; 
    }

    if (set_default_array_types_init() < 0) {
        fprintf(stderr,
                "[Lifecycle][ERROR] set_default_types_init() failed\n");
        return -1;
    }

    printf("[Lifecycle] global_init: default handler set\n");

    // Example for built-in “Int” dtype:
    if (array_types_init(_buildin_descrs[0], "Int_Dtype", NULL) < 0) {
        fprintf(stderr,
                "[Lifecycle][ERROR] type_init for \"Int\" failed\n");
        return -1;
    }

    printf("[Lifecycle] global_init: built-in \"Int\" registered\n");
    if (!default_handler_init()) {
       return -1 ; 
    }

    printf("[Lifecycle] global_init: runtime setup complete\n");
    runtime_initialized = 1 ;

    return 1;
}

