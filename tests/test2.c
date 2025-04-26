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
    ssize_t len1 = Get_VarSize(iarr1);
    int* iarr1data = IntArr_Data(iarr1);

    for (ssize_t i = 0; i < len1; i++) {
        iarr1data[i] = (int)i;
    }

    printf("iarr1 -> object of type: %s\n", Get_ObjType(iarr1));
    printf("\tData: ");
    for (ssize_t i = 0; i < len1; i++) {
        printf("%d ", iarr1data[i]);
    }
    printf("\n\n");

    /* Deallocate iarr1 (should push to freelist) */
    intarr_dealloc((Object*)iarr1);

    /* Allocate second IntArrObject (should reuse freelist) */
    IntArrObject* iarr2 = IntArr_New(5);

    /* Verify that iarr2 has the same layout and data */
    ssize_t len2 = Get_VarSize(iarr2);
    int* iarr2data = IntArr_Data(iarr2);

    printf("iarr2 -> object of type: %s\n", Get_ObjType(iarr2));
    printf("\tData: ");
    for (ssize_t i = 0; i < len2; i++) {
        printf("%d ", iarr2data[i]);
    }
    printf("\n\n");

    /* Check consistency */
    if (len1 == len2) {
        printf("Lengths match: %zd elements.\n", len1);
    } else {
        printf("Length mismatch: iarr1=%zd, iarr2=%zd\n", len1, len2);
    }

    int mismatch = 0;
    for (ssize_t i = 0; i < len1; i++) {
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

    /* Manual cleanup */
    Object_Free(iarr2);

    return 0;
}

