#include <stdio.h>
#include "Include/mem.h"
#include "Include/objimpl.h"
#include "Include/types.h"
#include "Include/clinic/tpobject.h"
#include "Include/clinic/intarrobj.h"

Object* 
intarr_new (TypeObject* tp) { 
    Object* ob = (Object* )Object_Malloc(tp->tp_basicsize) ; 
    return ob;
}
void
intarr_dealloc (Object* op) {
    Object_Free(op) ; 
    printf("its free ! \n") ; 
}
IntArrObject* 
intarr_alloc (ssize_t size) {
    return  Object_NewVar(IntArrObject,&IntArrObject_Type,size) ; 
}



IntArrObject* 
IntArr_New(ssize_t size) {
    IntArrObject* op;
    op = intarr_alloc(size) ; 
    for (ssize_t i =0 ; i<size ; i++){
        op->data._data[i] = 0 ; 
    }
    return op;
}


