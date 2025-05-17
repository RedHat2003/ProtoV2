#ifndef CAPSULE_H 
#define CAPSULE_H

#include "object.h"

typedef struct {
    Object_HEAD
    void* pointer ; 
    const char* name ; 
    void* context ; 
}CapsuleObj  ; 

#define Capsule_CAST(op) ((Capsule* )op)


Object* 
Capsule_New (void * , const char* ) ; 

#endif
