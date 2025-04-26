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
    printf("intarr_new: allocated object %p (tp_basicsize=%zu)\n", (void*)ob, tp->tp_basicsize);
    return ob;
}

void
intarr_dealloc(Object* ob)
{
    IntArrObject* op = (IntArrObject*)ob;
    ssize_t index = _SIZE(ob);
    if (_FREELIST_PUSH(intarrs[index - 1], op, intarr_MAXFREELIST)) {
        printf("intarr_dealloc: pushed object %p to freelist[%zd]\n", (void*)op, index - 1);
    } else {
        printf("intarr_dealloc: freelist[%zd] full, freeing object %p\n", index - 1, (void*)op);
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
            printf("intarr_alloc: popped object %p from freelist[%zd] (size=%zd)\n", (void*)op, index, size);
            return op;
        }
    }
    op = Object_NewVar(IntArrObject, &IntArrObject_Type, size);
    printf("intarr_alloc: freshly allocated object %p (size=%zd)\n", (void*)op, size);
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
    printf("IntArr_New: initialized data for object %p with size=%zd\n", (void*)op, size);
    return op;
}

int * 
intarr_data (Object* ob) {
    IntArrObject* op = _CAST(IntArrObject*,ob) ; 
    int* data = &(op->data._data[0]) ; 
    return data ;
}
