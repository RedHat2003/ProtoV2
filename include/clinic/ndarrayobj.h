#ifndef NDARRAYOBJ_H 
#define NDARRAYOBJ_H 

#include "object.h"
#include "objhelper.h"
#include "clinic/intarrobj.h"
#include "clinic/tpobject.h"

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
    _INT = 7 ,  
    NTYPES_LEGACY=0,
};

typedef struct _Array_Descr {
    Object_HEAD 
    TypeObject* typeobj ; 
    char kind ; 
    char type ; 
    char byteorder ; 
    char _former_flags ;
    int type_num ; 
    unsigned long flags ; 
    ssize_t elsize ; 
    ssize_t alignment ; 
    Object* metadata ;
    ssize_t hash ; 
    //for future used 
    void *reserved_null[2];
}Array_Descr ; 

#define ARRAY_DESCR_HEAD Array_Descr ad_base ; 

typedef struct {
    ARRAY_DESCR_HEAD 
    struct _arr_descr* subarray ; 
    Object* fields ;
    Object* names ;
    // NpyAuxData *c_metadata; 
}Array_LagacyDescr ; 
Array_Descr* Get(int ) ; 



typedef struct tagArrayObject_fields {
    Object_HEAD
    char* data ; 
    int nd ;
    IntArrObject*  layout ;
    /*
     * Number of bytes to jump to get to the
     * next element in each dimension
     */
    Object* base ; 
    Array_Descr* descr ; 
    int flags ; 
    Object* weakreflist ; // maybe i would change it to tuple latter 
}ArrayObject_fields;


Object* 
Array_New (
        TypeObject* subtype, int nd , int const* dims , int type_num ,
        int const* strides ,void* data, int flags,
        Object* obj) ; 

#endif
