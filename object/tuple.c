#include "clinic/tpobject.h"
#include "clinic/tupleobj.h"
#include "types.h"

TypeObject TupleObjet_Type = {
    .ob_base = {
        .ob_base = {   
            .ref_cnt =1 , 
            .tp_type = &TypeObject_Type 
        },
        .size = 0 
    },
    .tp_name = "tuple",
    .tp_basicsize =TupleObject_HEADER_SIZE,  // same as sizeof(TupleObjet) - sizeof (Objet* )
    .tp_itemsize = sizeof (Object*)
};


