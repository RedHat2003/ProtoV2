#include <stdio.h>
#include "objimpl.h"
#include "public.h"

int main (void) {
    TupleObject* t1 = Object_NewVar(TupleObject, &TupleObjet_Type, 3);
    TupleObject* t2 = Object_NewVar(TupleObject, &TupleObjet_Type, 10);
    printf ("the ref count of t1 , t2 is %zu , %zu\n" , Object_refcnt(t1) , Object_refcnt(t2));
    Object_Free(t1) ;
    Object_Free(t2) ; 
    return 0;
}
