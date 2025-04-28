#include "objimpl.h"
#include "public.h"
#include "array_api.h"
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

    Object_Free (ndarr) ; 
    return 0;
}
