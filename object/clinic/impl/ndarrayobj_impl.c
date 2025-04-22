#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include <stdio.h>   // for fprintf()
#include <stdlib.h>  // for abort()
#include <string.h>
#include "refcount.h"
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"

Array_Descr* 
Array_DescrFromType(int ); 

extern Array_LagacyDescr* _buildin_descrs[] ; 

Array_Descr* Get(int type) {
    if (__builtin_expect(type != NTYPES_LEGACY, 0)) {
        fprintf(stderr, "Invalid data-type for array: %d (expected: %d)\n", type, NTYPES_LEGACY);
        abort();  // or return NULL / error code as per your runtime
    }

    Array_Descr* ret = (Array_Descr*)_buildin_descrs[type];
    _INCREF((Object*)ret);
    return ret;
}


Object *
Array_NewFromDescr_int(
    TypeObject       *subtype,
    Array_Descr      *descr,
    int               nd,
    ssize_t   const *dims,
    ssize_t   const *strides,
    void             *data,
    int               flags,
    Object           *obj,    // unused
    Object           *base,   // stored but not otherwise used
    int               cflags) // unused
{
    ArrayObject_fields *fa;
    size_t               nbytes;
    ssize_t              length;

    /* silence unused-parameter warnings */
    (void)obj;
    (void)cflags;

    /* 1) only 1‑D arrays supported */
    if (nd != 1) {
        fprintf(stderr, "Array_New: only 1‑D arrays supported (nd=%d)\n", nd);
        return NULL;
    }

    /* 2) compute total bytes */
    length = dims[0];
    if (length < 0) {
        fprintf(stderr, "Array_New: negative dimension %zd\n", length);
        return NULL;
    }
    nbytes = (size_t)length * descr->elsize;

    /* 3) allocate the header */
    fa = (ArrayObject_fields *)subtype->tp_alloc(subtype, 0);
    if (fa == NULL) {
        return NULL;
    }

    /* 4) fill core fields */
    fa->nd          = nd;
    fa->descr       = descr;
    fa->flags       = flags;
    fa->base        = base;
    fa->weekreflist = NULL;

    /* 5) allocate or attach data buffer */
    if (data) {
        fa->data = (char*)data;
    }
    else {
        size_t alloc_size = nbytes ? nbytes : 1;
        fa->data = malloc(alloc_size);
        if (!fa->data) {
            free(fa);
            return NULL;
        }
        memset(fa->data, 0, alloc_size);
    }

    /* 6) set stride */
    if (strides) {
        fa->strides = strides[0];
    }
    else {
        fa->strides = descr->elsize;
    }

    return (Object*)fa;
}

Object *
Array_NewFromDescrAndBase(
        TypeObject *subtype, Array_Descr *descr,
        int nd, ssize_t const *dims, ssize_t const *strides, void *data,
        int flags, Object *obj, Object *base) {

    return Array_NewFromDescr_int(subtype, descr, nd,
                                    dims, strides, data,
                                    flags, obj, base, 0);

} 


Object* 
Array_NewFromDescr(
        TypeObject *subtype, Array_Descr *descr,
        int nd, ssize_t const *dims, ssize_t const *strides, void *data,
        int flags, Object *obj) {

    return Array_NewFromDescrAndBase(
            subtype, descr,
            nd, dims, strides, data,
            flags, obj, NULL);

}
Object* 
Array_New (
        TypeObject* subtype, int nd , ssize_t const* dims , int type_num ,
        ssize_t const* strides ,void* data, int flags,
        Object* obj) {
    Array_Descr* descr ; 
    Object* new ; 
    descr = Array_DescrFromType(type_num) ; 
    new = Array_NewFromDescr(subtype, descr, nd, dims, strides,
                               data, flags, obj);
    return new;
}

/** Dispatch to descriptor lookup. */
Array_Descr*
Array_DescrFromType(int type) {
    return Get(type);
}
