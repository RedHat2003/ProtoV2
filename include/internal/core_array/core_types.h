#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#include "object.h"
#include "clinic/ndarrayobj.h"

// A function that, when called, will wrap/initialize ALL your static types
typedef int (*TypeInitFunc)(Array_Descr* descr ,char* name , TypeObject* dtype_super_class );

// Declare the one-shot wrapper for all legacy dtypes
int wrap_legacy_types(Array_Descr* descr,char* name , TypeObject* dtype_super_class );


// Holds exactly one such init function
typedef struct {
    TypeInitFunc init_func;
} TypeInitRegistry;

#endif // CORE_TYPES_H

