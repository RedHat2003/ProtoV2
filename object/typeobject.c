#include "objimpl.h"
#include <string.h>
#include "internal/core_obmalloc.h"
#include "clinic/tpobject.h"



Object* 
Type_AllocNoTrack(TypeObject* type, ssize_t nitems) {
    Object* obj ; 
    ssize_t size = Object_Var_SIZE(type , nitems + 1) ; 
    const size_t presize =  0 ; // its just 0 until because there is no GC support until this moment .
    char* alloc = _Object_MallocWithType(type , size + presize) ;  
    obj = (Object*)(alloc + presize);
    /* Zero entire object memory (including header) */
    memset((char*)obj, 0, size);

    if (type->tp_itemsize == 0) {
        Object_Init(obj, type);
    }
    else {
        Object_Var_Init((VarObject *)obj, type, nitems);
    }
    return obj ; 

}

Object* 
Type_GenericAlloc (TypeObject* tp , ssize_t nitems) {
    Object* obj = Type_AllocNoTrack (tp ,nitems) ;  
    if (obj ==NULL) {
        return NULL;
    }
    return obj;
}


TypeObject TypeObject_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 0 ,
            .tp_type = &TypeObject_Type
        },
        .size = 0 
    },
    .tp_name = "type" , 
    .tp_alloc = 0, 
};
