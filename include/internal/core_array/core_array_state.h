#ifndef CORE_ARRAY_STATE_H
#define CORE_ARRAY_STATE_H

#include "core_types.h"
#include "core_mem.h"

typedef struct arrsubsys {
    TypeInitRegistry type_init ; 
    DataMem_Handler current_handler ;     
    // other would fall here //     
}_ArraySubSys ; 



#endif 
