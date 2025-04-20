#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include "refcount.h"
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

Array_Descr* 
Array_DescrFromType(int ); 

extern Array_LagacyDescr* _buildin_descrs[] ; 

Array_Descr* 
Get (int type ) {
    Array_Descr* ret = (Array_Descr*)_buildin_descrs[type]; 
    _INCREF((Object*)ret) ;  
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
