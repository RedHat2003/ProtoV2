#ifndef OBJECT_H
#define OBJECT_H
#include "objhelper.h"
#include "sys/types.h"


typedef struct typeobject TypeObject ; 

typedef struct object {
    ssize_t ref_cnt ; 
    TypeObject* tp_type ;
}Object;


typedef struct {
    Object ob_base ; 
    ssize_t size ; 
}VarObject; 

#define _SIZE(ob) ((VarObject*)ob)->size ; 

#define VarObject_HEAD VarObject ob_base ; 

typedef Object* (*newfunc) (TypeObject* ) ; 
typedef void (*destructor) (Object *);

#define Object_CAST(op) (Object* )(op)
#define Object_TYPE(op) ((Object*)op)->tp_type ; 
#define _CAST(type,op) ((type)op)  
#endif
