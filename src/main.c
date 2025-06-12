#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

#include "public.h"
#include "objimpl.h"
#include "clinic/capsule.h"

#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/_src/handler.h"
#include "clinic/array_api.h"

#include "internal/core_runtime.h"
#include "internal/core_runtime_init.h"
#include "internal/core_array/core_mem.h"

int main(void) {
    global_init();

    // 2D: 2 rows, 3 cols
    ssize_t dims[2] = {2, 3};
    Object* ndarr = Array_New(&ArrayObject_Type, 2, dims, 0, NULL, NULL, 0, NULL);
    ArrayObject_fields* fa = (ArrayObject_fields*)ndarr;

    printf("== Array Info ==\n");
    printf("Element size     : %zu bytes\n", fa->descr->elsize);

    printf("Dimensions       : ");
    for (int i = 0; i < 2; i++) {
        printf("%zu ", fa->dimensions[i]);
    }
    printf("\n");

    printf("Garbage (post-dims): ");
    for (int i = 2; i < 4; i++) {
        printf("%zu ", fa->dimensions[i]);
    }
    printf("\n");

    // Fill data
    {
        int rows = (int)dims[0];
        int cols = (int)dims[1];
        int* data_ptr = (int*)fa->data;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                data_ptr[r * cols + c] = r * cols + c + 1;
            }
        }

        printf("Data contents (2D):\n");
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                printf("%d ", data_ptr[r * cols + c]);
            }
            printf("\n");
        }
    }

    Object_Free(ndarr);

    DataMem_Handler* to_chandler = (DataMem_Handler*)Capsule_GetPointer(current_handler);
    printf("Current handler name: \"%s\"\n", to_chandler->name);

    void* test_mem = to_chandler->allocator.malloc(NULL, 64);
    if (test_mem) {
        printf("[OK] Allocation succeeded at %p\n", test_mem);
        to_chandler->allocator.free(NULL, test_mem);
        printf("[OK] Freed the allocated memory.\n");
    } else {
        printf("[ERR] Allocation failed.\n");
    }

    // 🔍 Compare pthread_self() and runtime_get_thread_ident()
    unsigned long manual_tid = (unsigned long)(uintptr_t)pthread_self();
    unsigned long from_run   = runtime_get_thread_ident(&_Runtime);

    printf("manual_tid = %lu\n", manual_tid);
    printf("from_run   = %lu\n", from_run);

    if (manual_tid == from_run) {
        printf("[OK] Thread IDs match!\n");
    } else {
        printf("[FAIL] Thread IDs differ!\n");
    }

    _Is_Initialized();
    return 0;
}

