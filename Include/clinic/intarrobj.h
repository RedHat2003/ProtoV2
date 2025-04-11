#ifndef INTARROBJ_H 

#define INTARROBJ_H

#include "Include/object.h"
#include "Include/objhelper.h"

struct _arr{
    int _data[1] ; 
};

typedef struct intarrobj {
    VarObject_HEAD 
    struct _arr data ; 
}IntArrObject ; 
DEFINE_STRUCT_HEADER_SIZE(IntArrObject,data._data) ;  
#endif
