#ifndef COBJECT_H 

#define COBJECT_H

#include "Include/object.h"

struct typeobject {
    VarObject_HEAD
    char* tp_name ; 
    ssize_t tp_basicsize , tp_itemsize ; 
    newfunc tp_new ; 
    destructor tp_dealloc ; 
};

#endif
