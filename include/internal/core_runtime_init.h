#ifndef CORE_RUNTIME_INIT 
#define CORE_RUNTIME_INIT 

#include "core_runtime.h" 
#include "core_mem.h"
#include "core_mem_init.h"

#define _RuntimeState_INIT(runtime)                       \
    {                                                     \
      .allocators = {                                     \
          .standard    = _mem_allocators_standard_INIT(), \
      },                                                  \
      .freelists = {                                      \
          .tuple_iters = {                                \
              .freelist = NULL,                           \
              .size     = 0                               \
          },                                              \
      },                                                  \
    }

#endif 

