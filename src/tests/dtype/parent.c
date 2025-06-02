#include <stdio.h>
#include "public.h"
#include "clinic/array_api.h"
#include "clinic/ndarray/ndarray_descr.h"

int main () {
    Array_Descr* int_desct = Array_DescrFromType(0) ;  
    printf ("Int Descr Type before Runtime init is : %s\n", int_desct->ob_base.tp_type->tp_name) ; 
    global_init() ; 
    printf ("Int Descr Type after Runtime init is : %s\n", int_desct->ob_base.tp_type->tp_name) ; 
    return 0;
}


