#ifndef CORE_MEM_INIT 
#define CORE_MEM_INIT

#include "core_mem.h"

#define RAW_ALLOC {_Mem_RawMalloc,_Mem_RawFree }  /* For Raw Domain */
#define MEM_ALLOC RAW_ALLOC
#define OBJ_ALLOC MEM_ALLOC

#define _mem_allocators_standard_INIT() \
    { \
        RAW_ALLOC, \
        MEM_ALLOC, \
        OBJ_ALLOC, \
    }


#endif
