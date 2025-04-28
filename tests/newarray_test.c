#include "public.h"
#include <stdio.h>
int main (void) {
    int dims[3] = {2, 3, 4};
    ArrayObject_fields* ndarr = (ArrayObject_fields* )Array_New(&ArrayObject_Type, 3, dims, 0, NULL, NULL, 0, NULL);    
    if (ndarr->flags & ARRAY_C_CONTIGUOUS){
        printf ("ARRAY_C_CONTIGUOUS flag is enabled \n");
    }   
    return 0;
}
