#include <stdio.h>
#include "Include/Public.h"
#include "Include/types.h"

int main(void) {
    IntArrObject* iarr = IntArr_New(10) ;     

    printf("the type of iarr is %s\n" , ((TypeObject*)iarr)->ob_base.ob_base.tp_type->tp_name) ; 
    Object_Dealloc(iarr) ; 
    return 0;
}

