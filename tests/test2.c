#include <stdio.h>
#include "objimpl.h"
#include "public.h"
#include "internal/core_freelist_state.h"
#include "internal/core_freelist.h"
#include "internal/core_tuple.h"

int main(void) {
    /* Allocate first IntArrObject */
    IntArrObject* iarr1 = IntArr_New(5);

    /* Initialize iarr1 with sequential values */
    int len1 = (int)Get_VarSize(iarr1);
    int* iarr1data = IntArr_Data(iarr1);

    for (int i = 0; i < len1; i++) {
        iarr1data[i] = i;
    }

    printf("iarr1 -> object of type: %s\n", Get_ObjType(iarr1));
    printf("\tData: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", iarr1data[i]);
    }
    printf("\n\n");

    /* Deallocate iarr1 (should push to freelist) */
    intarr_dealloc((Object*)iarr1);

    /* Allocate second IntArrObject (should reuse freelist) */
    IntArrObject* iarr2 = IntArr_New(5);

    /* Verify that iarr2 has the same layout and data */
    int len2 = (int)Get_VarSize(iarr2);
    int* iarr2data = IntArr_Data(iarr2);

    printf("iarr2 -> object of type: %s\n", Get_ObjType(iarr2));
    printf("\tData: ");
    for (int i = 0; i < len2; i++) {
        printf("%d ", iarr2data[i]);
    }
    printf("\n\n");

    if (len1 == len2) {
        printf("Lengths match: %d elements.\n", len1);
    } else {
        printf("Length mismatch: iarr1=%d, iarr2=%d\n", len1, len2);
    }

    int mismatch = 0;
    for (int i = 0; i < len1; i++) {
        if (iarr1data[i] != iarr2data[i]) {
            mismatch = 1;
            break;
        }
    }

    if (!mismatch) {
        printf("Data matches perfectly after freelist reuse.\n");
    } else {
        printf("Data mismatch after freelist reuse!\n");
    }

    Object_Free(iarr2);

    /* Test Array_New */
    int dims[3] = {2, 3, 4};
    Object* ndarr = Array_New(&ArrayObject_Type, 3, dims, 0, NULL, NULL, 0, NULL);
    if (ndarr != NULL) {
        printf("Array_New allocation succeeded.\n");
    } else {
        printf("Array_New allocation failed.\n");
    }
    ArrayObject_fields* fa = (ArrayObject_fields* )ndarr ; 
    for (int i = 0 ; i < fa->nd ; i++) {
        printf ("%d " , fa->layout->data._data[i]) ; 
    }
    printf("\n") ; 
    return 0;
}

