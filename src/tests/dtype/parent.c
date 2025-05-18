#include "public.h"
#include <stdio.h>
#include "clinic/array_api.h"
#include "clinic/tpobject.h"
#include "internal/core_runtime.h"

extern _RuntimeState _Runtime ; 
extern Array_Descr* _buildin_descrs[] ;

int main () {
    global_init() ; 
    Object* int_desct = (Object* )_buildin_descrs[0] ; 
    printf ("the name of the descr type is : %s\n" , int_desct->tp_type->tp_name) ; 
    return 0;
}


