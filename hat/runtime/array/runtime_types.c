#include <stdio.h>
#include <string.h>
#include "include/mem.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/_src/dtypemeta.h"
#include "internal/core_array/core_array_init.h"

int default_types_init(Array_Descr* descr,
                       char* name,
                       TypeObject* dtype_super_class)
{
    printf("[ArrayTypes] default_types_init: name=\"%s\", descr=%p\n",
           name, (void*)descr);

    if (Get_ObjType(descr) != &ArrayDtype_Type) {
        fprintf(stderr,
                "[ArrayTypes][ERROR] descriptor %p is not ArrayDtype_Type\n",
                (void*)descr);
        return -1;
    }

    DType_Slots* dt_slots = Mem_Malloc(sizeof(DType_Slots));
    if (!dt_slots) {
        fprintf(stderr,
                "[ArrayTypes][ERROR] Mem_Malloc(sizeof(DType_Slots)) failed\n");
        return -1;
    }
    memset(dt_slots, 0, sizeof(DType_Slots));

    Array_DTypeMeta* dtype_class = Mem_Malloc(sizeof(Array_DTypeMeta));
    if (!dtype_class) {
        fprintf(stderr,
                "[ArrayTypes][ERROR] Mem_Malloc(sizeof(Array_DTypeMeta)) failed\n");
        Mem_Free(dt_slots);
        return -1;
    }

    static const Array_DTypeMeta prototype = {
        .super = {
            .ob_base = {
                .ob_base = { .ref_cnt = 1,
                             .tp_type = &ArrayDTypeMeta_Type },
                .size     = 0
            },
            .tp_basicsize = sizeof(Array_Descr),
            .tp_base      = NULL,
            .tp_name      = NULL,  // we'll patch below
        },
    };
    memcpy(dtype_class, &prototype, sizeof(Array_DTypeMeta));

    ((TypeObject*)dtype_class)->tp_name = name;
    ((TypeObject*)dtype_class)->tp_base = dtype_super_class;
    dtype_class->dt_slots = dt_slots;

    SET_TYPE(descr, (TypeObject*)dtype_class);

    printf("[ArrayTypes] default_types_init: \"%s\" initialized successfully\n",
           name);
    return 0;
}

