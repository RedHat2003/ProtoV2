#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/_src/handler.h"
#include "objimpl.h"
#include "public.h"
#include "clinic/array_api.h"
#include "internal/core_array/core_mem.h"
#include <stdio.h>

int main(void) {
    ssize_t dims[3] = {1, 2, 3};
    Object* ndarr = Array_New(&ArrayObject_Type, 3, dims, 0, NULL, NULL, 0, NULL);
    ArrayObject_fields* fa = (ArrayObject_fields*)ndarr;

    printf("== Array Info ==\n");
    printf("Element size     : %zu bytes\n", fa->descr->elsize);

    printf("Dimensions       : ");
    for (int i = 0; i < 3; i++) {
        printf("%zu ", fa->dimensions[i]);
    }
    printf("\n");

    printf("Garbage (post-dims): ");
    for (int i = 3; i < 6; i++) {
        printf("%zu ", fa->dimensions[i]);
    }
    printf("\n");

    if (Get_ObjType(Array_DescrFromType(0)) == &ArrayDtype_Type) {
        printf("[OK] Default descriptor type is ArrayDtype_Type\n");
    } else {
        printf("[ERR] Descriptor type mismatch!\n");
    }

    Object_Free(ndarr);

    char* handler_name = currnet_handler_name();  // note: is this a typo? 'currnet'
    printf("Current handler name: \"%s\"\n", handler_name);

    return 0;
}

