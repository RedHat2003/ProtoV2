#ifndef TUPLEOBJ_C_H 
#define TUPLEOBJ_C_H


#include "Include/object.h"
#include "Include/clinic/tupleobj.h"
ssize_t _Tuple_GET_SIZE (Object* ) ; 
#define Tuple_GET_SIZE(op) _Tuple_GET_SIZE(Object_CAST(op)) 

#endif
