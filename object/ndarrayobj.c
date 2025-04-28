
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

#include <stdlib.h>
#include "mem.h"

#include "types.h"

static void ndarray_dealloc(Object *op)
{
    ArrayObject_fields *fa = (ArrayObject_fields *)op;

    /* release data buffer only if this ndarray owns it */
    if (fa->data && fa->base == NULL) {
        free(fa->data);            /* data came from plain malloc */
    }

    /* release dims/strides block allocated with Object_Malloc */
    if (fa->dimensions) {
        Object_Free(fa->dimensions);
    }

    /* DECREF other referenced objects when you add them */
    /* … */

    /* free the ndarray struct itself (Object_Malloc) */
    Object_Free(op);
}


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
    .tp_dealloc = ndarray_dealloc
    
};


