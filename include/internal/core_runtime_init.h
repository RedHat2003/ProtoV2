#ifndef CORE_RUNTIME_INIT
#define CORE_RUNTIME_INIT

#include "core_runtime.h"
#include "core_mem.h"
#include "core_mem_init.h"
#include "core_types.h"  /* for TypeInitRegistry */

// Declare the one-shot wrapper for all legacy dtypes
int wrap_legacy_types(Array_Descr* descr,char* name , TypeObject* dtype_super_class );

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
      .type_init = {                                      \
          .init_types  = wrap_legacy_types,               \
      }                                                   \
    }

#endif  /* CORE_RUNTIME_INIT */

