#ifndef TUPLEOBJ_H 
#define TUPLEOBJ_H

#include "Include/object.h"
#include "Include/objhelper.h"

typedef struct {
    VarObject_HEAD 
    Object* ob_item[1] ; 
}TupleObject ;

DEFINE_STRUCT_HEADER_SIZE (TupleObject , ob_item) ; 

/* Public API: get size of tuple */
ssize_t Tuple_GET_SIZE(Object* ob);
#endif 

