#ifndef BUFFOBJ_H 
#define BUFFOBJ_H

#include "object.h"
#include "objhelper.h"
#include "clinic/tpobject.h"


struct _farr {
    float _data[1] ;   
};

typedef struct buffobj {
    VarObject_HEAD 
    struct _farr data ;   
}FloatArrObject;


DEFINE_STRUCT_HEADER_SIZE(FloatArrObject,data._data) ; 

/* Public API: constructors and destructor */
Object* floatarr_new(TypeObject* tp, Object* args);
FloatArrObject* floatarr_alloc(ssize_t size);
FloatArrObject* FloatArr_New(ssize_t size);
void floatarr_dealloc(Object* op);



#endif 
