#include "object.h"
#include "objimpl.h"
#include "types.h"

#include "clinic/capsule.h"

Object* 
Capsule_New (void* ptr , const char* name ) {
    CapsuleObj* capsule ; 

    if (!ptr) {
        return NULL ; 
    }
    capsule = Object_New(CapsuleObj ,&Capsule_Type) ; 
    capsule->name = name ; 
    capsule->pointer = ptr ; 
    return (Object*)capsule;
}
