#ifndef INTARROBJ_H 

#define INTARROBJ_H

#include "Include/object.h"
#include "Include/objhelper.h"
#include "Include/clinic/tpobject.h"

struct _arr{
    int _data[1] ; 
};

typedef struct intarrobj {
    VarObject_HEAD 
    struct _arr data ; 
}IntArrObject ; 
DEFINE_STRUCT_HEADER_SIZE(IntArrObject,data._data) ;  

/* Public API: constructors and destructor */
Object* intarr_new(TypeObject* tp, Object* args);
IntArrObject* intarr_alloc(ssize_t size);
IntArrObject* IntArr_New(ssize_t size);
void intarr_dealloc(Object* op);
#endif
