#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include <stdio.h>   // for printf(), fprintf()
#include <stdlib.h>  // for abort(), malloc, free
#include <string.h>  // for memset

#include "refcount.h"
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"
#include "public.h"
#include "clinic/tupleobj.h"
#include "internal/core_freelist_state.h"
#include "internal/core_freelist.h"



int main(void) {
    /* --- existing tests --- */
    IntArrObject* iarr = IntArr_New(10);
    FloatArrObject* farr = FloatArr_New(10);

    _Freelists* fl = _freelist_GET();
    printf("the number is %zu\n", fl->tuple_iters.size);
    printf(
      "the tp_basicsize = %zu\n",
      TupleObjet_Type.tp_basicsize
    );
    printf(
      "alternative is sizeof(TupleObjet) - sizeof(Object*) = %zu\n",
      sizeof(TupleObject) - sizeof(Object*)
    );
    printf(
      "the type of iarr is %s\n",
      ((TypeObject*)iarr)->ob_base.ob_base.tp_type->tp_name
    );
    printf(
      "the type of farr  is %s\n",
      ((TypeObject*)farr)->ob_base.ob_base.tp_type->tp_name
    );

    Array_Descr* descr = Get(0);
    printf("the descr element size is %zu\n", descr->elsize);

    Object_Dealloc(iarr);
    Object_Dealloc(farr);

    /* --- new Array_New call for a 1×10 zeroed array --- */
    ssize_t dims[1] = { 10 };
    Object *arr = Array_New(
        /* subtype  */ &ArrayObject_Type,
        /* nd       */ 1,
        /* dims     */ dims,
        /* type_num */ 0,
        /* strides  */ NULL,
        /* data     */ NULL,
        /* flags    */ 0,
        /* obj      */ NULL
    );
    if (!arr) {
        fprintf(stderr, "Array_New failed\n");
        return 1;
    }

    printf(
      "the type of arr  is %s\n",
      ((TypeObject*)arr)->ob_base.ob_base.tp_type->tp_name
    );

    Object_Dealloc(arr);
    return 0;
}

