#include <stdio.h> 
#include "Include/mem.h"
#include "Include/objimpl.h"
#include "Include/clinic/tpobject.h"
#include "Include/clinic/tupleobj.h"
#include "Include/types.h"




#define _Tuple_Cast(ob) _CAST(TupleObject*,ob)

ssize_t _Tuple_GET_SIZE (Object* ob) {
    TupleObject* tuple = _Tuple_Cast(ob) ;
    return _SIZE(tuple);
}
