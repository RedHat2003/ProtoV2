#ifndef NDARRAYOBJ_H 
#define NDARRAYOBJ_H 

#include "object.h"
#include "objhelper.h"
#include "clinic/tpobject.h"

enum _TYPECHAR {
    _SIGNEDLTR = 'i', 
};
enum _TYPES {
    _INT = 7 
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

#endif
