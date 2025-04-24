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

Array_Descr* 
Array_DescrFromType(int ); 

extern Array_LagacyDescr* _buildin_descrs[] ; 


/* Private options for NewFromDescriptor */
typedef enum {
    /*
     * Indicate the array should be zeroed, we may use calloc to do so
     * (otherwise much like ).
     */
    _NPY_ARRAY_ZEROED = 1 << 0,
    /* Whether to allow empty strings (implied by ensure dtype identity) */
    _NPY_ARRAY_ALLOW_EMPTY_STRING = 1 << 1,
    /*
     * If we take a view into an existing array and use its dtype, then that
     * dtype must be preserved (for example for subarray and S0, but also
     * possibly for future dtypes that store more metadata).
     */
    _NPY_ARRAY_ENSURE_DTYPE_IDENTITY = 1 << 2,
} _NPY_CREATION_FLAGS;

Array_Descr* Get(int type) {
    if (__builtin_expect(type != NTYPES_LEGACY, 0)) {
        fprintf(stderr, "Invalid data-type for array: %d (expected: %d)\n", type, NTYPES_LEGACY);
        abort();  // or return NULL / error code as per your runtime
    }

    Array_Descr* ret = (Array_Descr*)_buildin_descrs[type];
    _INCREF((Object*)ret);
    return ret;
}

 
Object* 
Array_NewFromDescr_int(
      TypeObject* subtype , Array_Descr* descr ,int nd ,
      ssize_t const* dims , ssize_t const* strides , void* data ,
      int flags , Object* obj , Object* base , _NPY_CREATION_FLAGS cflags ){
    
    ArrayObject_fields* fa ; 
    ssize_t nbytes ; 
    
    if (nd > MAXDIMS || nd < 0 ) {
       //ref dec of descr 
       return NULL ;
    }
    nbytes = descr->elsize ; 

    fa = (ArrayObject_fields* )subtype->tp_alloc(subtype , 0 ) ; 

    if (fa ==NULL ) {
        //ref dec of descr 
        return NULL;
    }

    fa->nd = nd ; 
    fa->dimensions = NULL ; 
    fa->weakreflist = NULL ; 
    fa->data = NULL ; 

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

/** Dispatch to descriptor lookup. */
Array_Descr*
Array_DescrFromType(int type) {
    return Get(type);
}
