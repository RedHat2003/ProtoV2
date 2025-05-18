#ifndef CORE_ARRAY_INIT_H
#define CORE_ARRAY_INIT_H

#include "core_types.h"        // for TypeInitRegistry
#include "clinic/ndarrayobj.h"  // for Array_Descr
#include "clinic/tpobject.h"    // for TypeObject

// The “default” implementation
int default_types_init(Array_Descr *descr,
                       char *name,
                       TypeObject *dtype_super_class);

// Wire it into the RuntimeState
int set_default_types_init(void);

// Helper to run the current init_func
int type_init(Array_Descr *descr,
              char *name,
              TypeObject *dtype_super_class);

#endif  /* CORE_ARRAY_INIT_H */

