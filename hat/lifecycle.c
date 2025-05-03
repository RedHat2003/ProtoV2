#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"

_RuntimeState _Runtime = _RuntimeState_INIT(Runtime) ; 

int type_init(){
    if (_Runtime.type_init.init_types()) {
        return 1;
    }
    else {
        return -1;
    }
}
