#include <stdio.h>
#include "object.h"
#include "objimpl.h"

void _INCREF(Object* ob) {
    printf ("ref count were %zu ",ob->ref_cnt) ; 
    ob->ref_cnt++ ; 
    printf ("but now %zu\n" , ob->ref_cnt) ; 
}

void _DECREF(Object* op) {
    if (--op->ref_cnt == 0 ){
        Object_Dealloc(op) ; 
    }
}

void _NEWREF(Object* op) {
    op->ref_cnt = 1 ; 
}
