#ifndef CORE_MEM_INIT_H 
#define CORE_MEM_INIT_H
#include "core_mem.h"


#define _DATAMEM_HANDLER_DEFAULT() \
{                                  \
    "default_handler",             \
    {                              \
        NULL,                      \
        default_malloc,            \
        default_free               \
    }                              \
}


#endif
