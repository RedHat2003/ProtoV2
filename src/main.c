#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "objimpl.h"
#include "public.h"
#include "clinic/array_api.h"
#include <stdio.h>


int main (void) {
    ssize_t dims[3] = { 1,2,3 };
    Object* ndarr = Array_New(&ArrayObject_Type, 3, dims, 0, NULL, NULL, 0, NULL);
    ArrayObject_fields* fa = (ArrayObject_fields* )ndarr ; 
    printf("the size of element is :%zu\n" , fa->descr->elsize) ; 
    
    for (int i =0 ; i<3 ; i++) {
        printf("%zu ",fa->dimensions[i]) ; 
    }
    printf("\n") ; 
    
    for (int i = 3 ; i <6 ; i++) {
        printf("%zu " , fa->dimensions[i] ) ; 
    }
    printf("\n") ; 
    if (Get_ObjType(Array_DescrFromType(0))==&ArrayDtype_Type){
        printf ("all is good ! \n") ; 
    }

    Object_Free (ndarr) ;
    Array_Descr* descr = Array_DescrFromType(0) ; 
    if (type_init(descr)) {
        printf ("its what it is \n") ; 
    }
    return 0;
}
