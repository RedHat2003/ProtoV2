#include <stdio.h>
#include <stdlib.h>
#include "public.h"
#include "clinic/tupleobj.h"
#include "types.h"
#include "internal/core_freelist_state.h"
#include "internal/core_freelist.h"




int main(void) {

    IntArrObject* iarr = IntArr_New(10) ;     
    FloatArrObject* farr = FloatArr_New (10) ;
    _Freelists* fl = _freelist_GET() ;   
    printf ("the number is %zu\n" , fl->tuple_iters.size) ; 
    printf ("the tp_basicsize = %zu\n" , TupleObjet_Type.tp_basicsize)  ; 
    printf ("alternative is sizeof(TupleObjet) - sizeof (Object*) = %zu\n" , sizeof(TupleObject) - sizeof (Object* )) ; 
    printf("the type of iarr is %s\n" , ((TypeObject*)iarr)->ob_base.ob_base.tp_type->tp_name) ; 
    printf("the type of farr is %s\n" , ((TypeObject*)farr)->ob_base.ob_base.tp_type->tp_name) ; 
    Object_Dealloc(iarr) ; 
    Object_Dealloc (farr) ; 
    return 0;
}

