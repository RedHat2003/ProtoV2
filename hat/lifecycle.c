#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"
#include <public.h>
_RuntimeState _Runtime = _RuntimeState_INIT(Runtime) ; 

int type_init(Array_Descr* descr ){
    if (_Runtime.type_init.init_types(descr)) {
        return 1;
    }
    else {
        return -1;
    }
}
