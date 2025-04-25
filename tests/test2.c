#include <stdio.h>
#include "objimpl.h"
#include "public.h"
#include "internal/core_freelist_state.h"

#include "internal/core_freelist.h"
#include "internal/core_tuple.h"

int main (void) {
    TupleObject* t1 = Object_NewVar(TupleObject, &TupleObjet_Type, 3);
    TupleObject* t2 = Object_NewVar(TupleObject, &TupleObjet_Type, 10);
    printf ("the ref count of t1 , t2 is %zu , %zu\n" , Object_refcnt(t1) , Object_refcnt(t2));
    printf ("the size of tuple_iters %zu\n" ,_FREELIST_SIZE(tuple_iters) ) ; 
    ssize_t index = t1->ob_base.size - 1 ; 
    int status = _FREELIST_PUSH(tuples[index], t1, tuple_MAXFREELIST) ;  
    if (status) {
        printf("pushed ! \n") ; 
    }
    else {
        return 0;
    }
    TupleObject* t_frompush = _FREELIST_POP(TupleObject, tuples[index]) ; 
    printf ("the size from pushed is %zu\n" , t_frompush->ob_base.size) ; 
    Object_Free(t2) ; 
    return 0;
}
