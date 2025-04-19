#ifndef CORE_TUPLE_H 
#define CORE_TUPLE_H 

#include <object.h>
#include <clinic/tupleobj.h>

typedef struct {
    Object_HEAD
    ssize_t index ; 
    TupleObject it_seq ; 
}_TupleIterObject;

#endif
