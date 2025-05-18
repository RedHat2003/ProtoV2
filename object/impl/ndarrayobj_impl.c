#include "mem.h"
#include "object.h"
#include "objimpl.h"
#include "types.h"
#include <stdio.h>   // for fprintf()
#include <stdlib.h>  // for abort()
#include <string.h>
#include "refcount.h"
#include "public.h"
#include "clinic/tpobject.h"
#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_helpers.h"
#include "clinic/ndarray/ndarray_dtype.h"


Array_Descr* 
Array_DescrFromType(int ); 

extern Array_Descr* _buildin_descrs[] ; 

/* Private options for NewFromDescriptor */
typedef enum {
    _NPY_ARRAY_ZEROED = 1 << 0,
    _NPY_ARRAY_ALLOW_EMPTY_STRING = 1 << 1,
    _NPY_ARRAY_ENSURE_DTYPE_IDENTITY = 1 << 2,
} _NPY_CREATION_FLAGS;

Array_Descr* Array_DescrFromType(int type) {

    Array_Descr* ret = _buildin_descrs[type];
    _INCREF((Object*)ret);
    return ret;
}
static void
_array_fill_strides(ssize_t* strides,
                    const ssize_t *dims,
                    int nd,
                    ssize_t itemsize,
                    int *objflags)
{
    /* Compute C-order strides (row-major) */
    for (int i = nd - 1; i >= 0; --i) {
        strides[i] = itemsize;
        itemsize *= dims[i];
    }

    /* Mark as C-contiguous */
    *objflags |= ARRAY_C_CONTIGUOUS ;
} 

Object* 
Array_NewFromDescr_int(
      TypeObject* subtype , Array_Descr* descr ,int nd ,
      ssize_t const* dims , ssize_t const* strides , void* data ,
      int flags , Object* obj , Object* base , _NPY_CREATION_FLAGS cflags ){
    
    ArrayObject_fields* fa ; 
    int nbytes ; 
    // Explicitly mark variables as unused to prevent compiler warnings
    (void)nbytes;
    (void)strides;
    (void)obj;
    (void)base;
    (void)cflags;
    (void)dims ; 

    if (nd > MAXDIMS || nd < 0 ) {
       return NULL ;
    }
    nbytes = descr->elsize ;

    fa = (ArrayObject_fields* )subtype->tp_alloc(subtype , 0 ) ; 

    if (fa == NULL) {
        return NULL;
    }

    fa->nd = nd ; 
    fa->dimensions = NULL ;
    fa->weakreflist = NULL ; 
    fa->data = NULL ; 
    if (data ==NULL) {
        fa->flags = ARRAY_DEFAULT ; 
        if (flags) {
           flags = ARRAY_C_CONTIGUOUS ; 
        }
    }
    else {
        data = NULL ; 
        //just for this moment ! 
    }

    fa->descr = descr ; 
    fa->base = (Object* )NULL ; 
    fa->weakreflist = (Object* )NULL ; 
     

    fa->descr = descr ; 
    fa->base = (Object* )NULL ; 
    fa->weakreflist = (Object* )NULL ; 
     
    if (nd > 0 ) {
        fa->dimensions = (ssize_t* )dim_alloc(2 * nd) ; 
        fa->strides = fa->dimensions + nd ; 

        for (int i = 0 ; i <nd ; i++) {
            fa->dimensions[i] = dims[i] ; 
        }

        if (strides ==NULL) {
            _array_fill_strides(fa->strides, dims, nd, descr->elsize,
                                &(fa->flags));
        }
    }
 

    return (Object* )fa ; 
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


