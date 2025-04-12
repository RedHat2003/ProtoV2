#include <stdio.h>
#include "Include/Public.h"

int main (void) {
    IntArrObject* line = IntArr_New(10) ; 
    for (ssize_t i =0 ; i<line->ob_base.size ; i ++) {
        printf ("%d " , line->data._data[i]) ; 
    }
    return 0;
}
