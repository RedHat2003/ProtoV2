#include <stdio.h> 
#include "Include/mem.h"
#include "Include/objimpl.h"
#include "Include/clinic/tpobject.h"
#include "Include/clinic/tupleobj.h"
#include "Include/types.h"




#define _Tuple_Cast(ob) _CAST(TupleObject*,ob)

ssize_t Tuple_GET_SIZE (Object* ob) {
    TupleObject* tuple = _Tuple_Cast(ob) ;
    return _SIZE(tuple);
}

#define Tuple_GET_ITEM(op, index) (_Tuple_Cast(op))->ob_item[(index)]

Object* tuple_new_impl (TypeObject* type , Object* iterable ) ; 

Object*
tuple_new (TypeObject* type, Object* args) {
    Object* returned;
    Object* iterable = NULL;

    if (Tuple_GET_SIZE(args) < 1 ) {
        return NULL ;
    }
    returned = tuple_new_impl(type , iterable) ;  
    return returned ; 
}
Object* tuple_new_impl (TypeObject* type, Object* iterable) {
    (void)type;
    if (iterable == NULL) {
        return NULL;
    }
    return NULL;
}
