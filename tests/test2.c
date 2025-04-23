#include "public.h"

int main (void) {
    TupleObject* t1 = Object_NewVar(TupleObject, &TupleObjet_Type, 3);
    TupleObject* t2 = Object_NewVar(TupleObject, &TupleObjet_Type, 3);
    Object_Free(t1) ; 
    Object_Free(t2) ; 
    return 0;
}
