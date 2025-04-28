#ifndef NDARRAYOBJ_H 
#define NDARRAYOBJ_H 

#include "object.h"
#include "objhelper.h"
#include "clinic/tpobject.h"
#include <stdio.h>

#define MAXDIMS 64 
#define MAXDIMS_LEGACY_ITERS 32
#define FAIL 0
#define SUCCEED 1

// Individual flags: one bit per property
#define ARRAY_C_CONTIGUOUS    0x0001  // 0000 0000 0000 0001 (bit 0)
#define ARRAY_WRITEABLE       0x0002  // 0000 0000 0000 0010 (bit 1)
#define ARRAY_ALIGNED         0x0004  // 0000 0000 0000 0100 (bit 2)

// Combined flags
#define ARRAY_BEHAVED (ARRAY_ALIGNED | \
                       ARRAY_WRITEABLE)

// Default flags: behaved + C order
#define ARRAY_DEFAULT (ARRAY_BEHAVED | \
                       ARRAY_C_CONTIGUOUS)

// (Optional) later you can define Fortran order
// #define ARRAY_F_CONTIGUOUS  0x0008  // 0000 0000 0000 1000 (bit 3)


enum _TYPECHAR {
    _SIGNEDLTR = 'i', 
};
enum _TYPES {
    _INT = 0 ,  
};

typedef struct _Array_Descr {
    Object_HEAD 
    TypeObject* typeobj ; 
    int type_num ; 
    unsigned long flags ; 
    ssize_t elsize ; 
    ssize_t alignment ; 
}Array_Descr ; 



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

Object* 
Array_New (
        TypeObject* subtype, int nd , ssize_t const* dims , int type_num ,
        ssize_t const* strides ,void* data, int flags,
        Object* obj) ; 

#endif
