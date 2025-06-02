#include <stdio.h>
#include <stdlib.h>

#include "public.h"
#include "objimpl.h"
#include "clinic/capsule.h"

#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/_src/handler.h"
#include "clinic/array_api.h"

#include "internal/core_runtime.h"
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
    // printing extra garbage slots just like before
    for (int i = 2; i < 4; i++) {
        printf("%zu ", fa->dimensions[i]);
    }
    printf("\n");

    // —————————
    // Populate fa->data as a 2×3 int32 buffer
    // —————————
    {
        int rows = (int)dims[0];   // 2
        int cols = (int)dims[1];   // 3
        int* data_ptr = (int*)fa->data;

        // fill row-major: row 0→(1,2,3), row 1→(4,5,6)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                data_ptr[r * cols + c] = r * cols + c + 1;
            }
        }

        // print as 2D
        printf("Data contents (2D):\n");
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                printf("%d ", data_ptr[r * cols + c]);
            }
            printf("\n");
        }
    }

    Object_Free(ndarr);

    // 🔥 Get the current handler and print name
    DataMem_Handler* to_chandler = (DataMem_Handler*)Capsule_GetPointer(current_handler);
    printf("Current handler name: \"%s\"\n", to_chandler->name);

    // 🔥 Allocate and free test
    void* test_mem = to_chandler->allocator.malloc(NULL, 64);  // Allocate 64 bytes
    if (test_mem) {
        printf("[OK] Allocation succeeded at %p\n", test_mem);
        to_chandler->allocator.free(NULL, test_mem);
        printf("[OK] Freed the allocated memory.\n");
    } else {
        printf("[ERR] Allocation failed.\n");
    }

    _Is_Initialized();
    return 0;
}

