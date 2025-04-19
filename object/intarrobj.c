#include "clinic/tpobject.h"
#include "clinic/intarrobj.h"
// #include "clinic/intarrobj.c.h"  // implementation header removed, prototypes moved to include/clinic/intarrobj.h
#include "types.h"

TypeObject IntArrObject_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 1 ,
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



