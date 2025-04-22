
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

#include "types.h"


TypeObject ArrayObject_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 1 , 
            .tp_type = &TypeObject_Type 
        },
        .size = 0
    },
    .tp_basicsize = sizeof (ArrayObject_fields) ,
    .tp_name = "ndarray" , 
    .tp_alloc = Type_GenericAlloc,
    .tp_dealloc = NULL 
    
};
