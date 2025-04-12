#ifndef BUFFOBJ_H 
#define BUFFOBJ_H

#include "Include/object.h"
#include "Include/objhelper.h"


struct _farr {
    float _data[1] ;   
};

typedef struct buffobj {
    VarObject_HEAD 
    struct _farr data ;   
}FloatArrObject;


DEFINE_STRUCT_HEADER_SIZE(FloatArrObject,data._data) ; 



#endif 
