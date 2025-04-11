#include "Include/clinic/tpobject.h"
#include "Include/clinic/intarrobj.h"
#include "clinic/intarrobj.c.h"
#include <Include/types.h>

TypeObject IntArrObject_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 0 ,
            .tp_type = &TypeObject_Type
        },
        .size = 0 
    },
    .tp_name = "intarr",
    .tp_basicsize = IntArrObject_HEADER_SIZE,
    .tp_itemsize = sizeof(int) ,
    .tp_new = intarr_new ,
    .tp_dealloc = intarr_dealloc 
};



