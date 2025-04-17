#include <stdio.h>
#include "Include/mem.h"
#include "Include/objimpl.h"
#include "Include/types.h"
#include "Include/clinic/tpobject.h"
#include "Include/clinic/floatarrobj.h"


Object*
floatarr_new (TypeObject* tp, Object* args) {
    (void)args;
    Object* ob = (Object*)Object_Malloc(tp->tp_basicsize);
    return ob;
}

FloatArrObject* 
floatarr_alloc (ssize_t size) {
    return Object_NewVar(FloatArrObject, &FloatArrObject_Type, size);
}

void floatarr_dealloc (Object* op) {
    Object_Free(op) ; 
}
FloatArrObject* 
FloatArr_New (ssize_t size){
    FloatArrObject* op ; 
    op = floatarr_alloc (size) ; 
    for (ssize_t i =0 ; i<size ; i++) {
        op->data._data[i] = 0.0 ; 
    }
    return op;
}
