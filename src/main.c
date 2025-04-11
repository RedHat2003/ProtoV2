#include <stdio.h>
#include <stdlib.h>
#include "Include/Public.h"
#include "Include/types.h"
#include <sys/types.h>

int main(void) {
    // Print initial type reference count
    printf("Initial type ref count: %ld\n", IntArrObject_Type.ob_base.ob_base.ref_cnt);
    
    // Create a dummy object to test creation and initialization.
    Object* dummy = IntArrObject_Type.tp_new(&IntArrObject_Type);
    Object_Init(dummy, &IntArrObject_Type);
    printf("Dummy object created; dummy ref count: %ld\n", dummy->ref_cnt);
    free(dummy);
    
    // Create an array with 100 elements.
    IntArrObject* iarr = IntArr_New(100);
    printf("IntArr_New created an object with ref count: %ld\n", ((Object*)iarr)->ref_cnt);
    
    // Modify the 100-element array data.
    for (ssize_t i = 0; i < 100; i++) {
        iarr->data._data[i] = (int)(i * 2);
    }
    
    // Print the entire 100-element array.
    printf("Data of the 100-element array:\n");
    for (ssize_t i = 0; i < 100; i++) {
        printf("%d ", iarr->data._data[i]);
    }
    printf("\n");
    
    // Print type ref count after creating the 100-element array.
    printf("Type ref count after 100-element array: %ld\n", IntArrObject_Type.ob_base.ob_base.ref_cnt);
    
    free(iarr);
    
    // Create two smaller arrays.
    IntArrObject* arr1 = IntArr_New(10);
    IntArrObject* arr2 = IntArr_New(20);
    
    // Modify arr1 data.
    for (ssize_t i = 0; i < 10; i++) {
        arr1->data._data[i] = (int)(i + 100);
    }
    
    // Modify arr2 data.
    for (ssize_t i = 0; i < 20; i++) {
        arr2->data._data[i] = (int)(i + 200);
    }
    
    // Print arr1 data and its ref count.
    printf("Data of the 10-element array:\n");
    for (ssize_t i = 0; i < 10; i++) {
        printf("%d ", arr1->data._data[i]);
    }
    printf("\n10-element array ref count: %ld\n", ((Object*)arr1)->ref_cnt);
    
    // Print arr2 data and its ref count.
    printf("Data of the 20-element array:\n");
    for (ssize_t i = 0; i < 20; i++) {
        printf("%d ", arr2->data._data[i]);
    }
    printf("\n20-element array ref count: %ld\n", ((Object*)arr2)->ref_cnt);
    
    // Check that each new object's reference count is 1.
    if (((Object*)arr1)->ref_cnt == 1 && ((Object*)arr2)->ref_cnt == 1) {
        // ANSI escape sequence for green: "\033[0;32m" and reset: "\033[0m"
        printf("\033[0;32m[passed]\033[0m\n");
    } else {
        printf("[failed]\n");
    }
    
    free(arr1);
    free(arr2);
    
    return 0;
}

