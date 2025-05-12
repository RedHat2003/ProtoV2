#include "public.h"
#include "clinic/array_api.h"
#include "clinic/tpobject.h"
#include <stdio.h>

extern Array_DTypeMeta Array_IntAbstractSType ; 


int main () {
    char* IntAbs_name = ((TypeObject* )&Array_IntAbstractSType)->tp_name ; 
    printf ("%s\n" , IntAbs_name) ;
    return 0;
}


