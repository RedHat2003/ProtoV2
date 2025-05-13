#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

// includable from ndarray/_src/dtypemeta.h 
TypeObject ArrayDTypeMeta_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 1 ,
            .tp_type = NULL  
        },
        .size = 0 
    },
    .tp_basicsize = sizeof (Array_DTypeMeta) , 
    .tp_name = "DTypeMeta" ,
    .tp_base = NULL  
} ; 
