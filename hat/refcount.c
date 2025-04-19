#include "object.h"
#include "objimpl.h"

void _INCREF(Object* ob) {
    ob->ref_cnt++ ; 
}

void _DECREF(Object* op) {
    if (--op->ref_cnt == 0 ){
        Object_Dealloc(op) ; 
    }
}

void _NEWREF(Object* op) {
    op->ref_cnt = 1 ; 
}
