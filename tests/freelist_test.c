#include "public.h"
#include "internal/core_freelist.h"
#include "internal/core_freelist_state.h"
#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

// Test freelist reuse
static int test_freelist_reuse(void) {
    IntArrObject* iarr1 = IntArr_New(5);
    if (!iarr1) {
        return 0; // Test failed
    }
    void* addr1 = (void*)iarr1;
    intarr_dealloc((Object*)iarr1);

    IntArrObject* iarr2 = IntArr_New(5);
    if (!iarr2) {
        return 0; // Test failed
    }
    void* addr2 = (void*)iarr2;
    intarr_dealloc((Object*)iarr2);

    return addr1 == addr2;
}

int main(void) {
    printf("Test freelist reuse ");
    if (test_freelist_reuse()) {
        printf(COLOR_GREEN "[ OK ]" COLOR_RESET "\n");
        return EXIT_SUCCESS;
    } else {
        printf(COLOR_RED "[ FAIL ]" COLOR_RESET "\n");
        return EXIT_FAILURE;
    }
}

