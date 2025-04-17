#include "Include/clinic/tpobject.h"
#include "Include/clinic/floatarrobj.h"
// #include "clinic/floatarrobj.c.h"  // implementation header removed, prototypes in Include/clinic/floatarrobj.h
#include <Include/types.h>

TypeObject FloatArrObject_Type  = {
    .ob_base = {
       .ob_base = {
            .ref_cnt = 1 ,
            .tp_type = &TypeObject_Type
       }, 
       .size = 0 
    },
    .tp_name = "floatarr",
    .tp_basicsize = FloatArrObject_HEADER_SIZE ,
    .tp_itemsize = sizeof(float) , 
    .tp_dealloc = floatarr_dealloc , 
    .tp_new = floatarr_new , 

} ; 
