#ifndef COBJECT_H 

#define COBJECT_H

#include "object.h"

struct typeobject {
    VarObject_HEAD
    char* tp_name ; 
    ssize_t tp_basicsize , tp_itemsize ; 
    newfunc tp_new ; 
    destructor tp_dealloc ; 
    allocfunc tp_alloc ; 
};

Object* 
Type_GenericAlloc (TypeObject* tp , ssize_t nitems) ;  
#endif
