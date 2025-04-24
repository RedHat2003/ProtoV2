#ifndef NDARRAYOBJ_H 
#define NDARRAYOBJ_H 

#include "object.h"
#include "objhelper.h"
#include "clinic/tpobject.h"

#define MAXDIMS 64 
#define MAXDIMS_LEGACY_ITERS 32
#define FAIL 0
#define SUCCEED 1

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
    ssize_t* dimensions ;
    /*
     * Number of bytes to jump to get to the
     * next element in each dimension
     */
    ssize_t strides ; 
    Object* base ; 
    Array_Descr* descr ; 
    int flags ; 
    Object* weakreflist ; // maybe i would change it to tuple latter 
}ArrayObject_fields;


Object* 
Array_New (
        TypeObject* subtype, int nd , ssize_t const* dims , int type_num ,
        ssize_t const* strides ,void* data, int flags,
        Object* obj) ; 

#endif
