#include <stdio.h>
#include "Include/Public.h"
#include "Include/types.h"

void linspace(float* data, size_t size) {
    // If there are no elements, do nothing.
    if (size == 0) return;

    // If there is only one element, we simply set it to 0.0.
    if (size == 1) {
        data[0] = 0.0f;
        return;
    }

    // Calculate the increment between consecutive values.
    // This creates 'size' evenly spaced values from 0.0 to 1.0.
    float step = 1.0f / (size - 1);

    // Fill the array.
    for (size_t i = 0; i < size; i++) {
        data[i] = i * step;
    }
}

int main(void) {

    IntArrObject* iarr = IntArr_New(10) ;     
    FloatArrObject* farr = FloatArr_New (10) ; 

    printf("the type of iarr is %s\n" , ((TypeObject*)iarr)->ob_base.ob_base.tp_type->tp_name) ; 
    printf("the type of farr is %s\n" , ((TypeObject*)farr)->ob_base.ob_base.tp_type->tp_name) ; 
    linspace ((farr->data._data) , farr->ob_base.size) ; 
    Object_Dealloc(iarr) ; 
    Object_Dealloc (farr) ; 
    return 0;
}

