#include "public.h"
#include <stdio.h>
int main (void) {
    int dims[3] = {2, 3, 4};
    ArrayObject_fields* ndarr = (ArrayObject_fields* )Array_New(&ArrayObject_Type, 3, dims, 0, NULL, NULL, 0, NULL);    
    TypeObject* descr_tp = ndarr->descr->ob_base.tp_type ; 
    printf ("the descr type is %s \nand the type of descr type is %s\n" , descr_tp->tp_name , descr_tp->ob_base.ob_base.tp_type->tp_name) ; 
    if (ndarr->flags & ARRAY_C_CONTIGUOUS){
        printf ("ARRAY_C_CONTIGUOUS flag is enabled \n");
    }   
    return 0;
}
