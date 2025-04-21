#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include <stdio.h>   // for fprintf()
#include <stdlib.h>  // for abort()

#include "refcount.h"
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

Array_Descr* 
Array_DescrFromType(int ); 

extern Array_LagacyDescr* _buildin_descrs[] ; 

Array_Descr* Get(int type) {
    if (__builtin_expect(type != NTYPES_LEGACY, 0)) {
        fprintf(stderr, "Invalid data-type for array: %d (expected: %d)\n", type, NTYPES_LEGACY);
        abort();  // or return NULL / error code as per your runtime
    }

    Array_Descr* ret = (Array_Descr*)_buildin_descrs[type];
    _INCREF((Object*)ret);
    return ret;
}


//Object* 
//Array_New (
//        TypeObject* subtype, int nd , ssize_t const* dims , int type_num ,
//        ssize_t const* strides ,void* data, int itemsize , int flags,
//        Object* obj) {
//    Array_Descr* descr ; 
//    Object* new ; 
//    descr = Array_DescrFromType(type_num) ; 
//   
//}
