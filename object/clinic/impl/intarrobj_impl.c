#include <stdio.h>
#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include "clinic/tpobject.h"
#include "clinic/intarrobj.h"
#include "internal/core_freelist_state.h"
#include "internal/core_freelist.h"

Object *
intarr_new(TypeObject* tp, Object* args)
{
    (void)args;
    Object *ob = Object_Malloc(tp->tp_basicsize);
    return ob;
}

void
intarr_dealloc(Object* ob)
{
    IntArrObject* op = (IntArrObject*)ob;
    ssize_t index = _SIZE(ob);
    if (_FREELIST_PUSH(intarrs[index - 1], op, intarr_MAXFREELIST)) {
    } else {
        Object_Free(ob);
    }
}

IntArrObject *
intarr_alloc(ssize_t size)
{
    IntArrObject* op = NULL;
    ssize_t index = size - 1;
    if (index < IntArr_MAXSAVESIZE) {
        op = _FREELIST_POP(IntArrObject, intarrs[index]);
        if (op) {
            return op;
        }
    }
    op = Object_NewVar(IntArrObject, &IntArrObject_Type, size);
    return op;
}

IntArrObject *
IntArr_New(ssize_t size)
{
    IntArrObject* op = intarr_alloc(size);
    if (op == NULL) {
        fprintf(stderr, "IntArr_New: out of memory\n");
        abort();
    }
    /* Initialize inline data array (flexible member) */
    for (ssize_t i = 0; i < size; ++i) {
        op->data._data[i] = 0;
    }
    return op;
}

int * 
intarr_data (Object* ob) {
    IntArrObject* op = _CAST(IntArrObject*,ob) ; 
    int* data = &(op->data._data[0]) ; 
    return data ;
}
