#ifndef NDARRAYOBJ_H 
#define NDARRAYOBJ_H 

#include "object.h"
#include "objhelper.h"
#include "clinic/tpobject.h"
#include "ndarray/ndarray_descr.h"
#include "ndarray/ndarray_flags.h"


#define MAXDIMS 64 
#define MAXDIMS_LEGACY_ITERS 32
#define FAIL 0
#define SUCCEED 1



typedef struct tagArrayObject_fields {
    Object_HEAD
    int nd ;
    ssize_t*  dimensions ;
    ssize_t* strides ; 
    Object* base ; 
    Object* weakreflist ; // maybe i would change it to tuple latter 
    Array_Descr* descr ; 
    int flags ; 
    char* data ; 
}ArrayObject_fields;

typedef struct  {
    TypeObject super ;
    TypeObject* scalar_type ; 
    void* dt_slots ; 
} Array_DTypeMeta; 




#endif
