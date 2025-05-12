
#include "include/mem.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/array_api.h"
#include <stdio.h>
#include <string.h>

int  wrap_legacy_types(Array_Descr* descr ) {
    int has_type = Get_ObjType(descr) == &ArrayDtype_Type ; 
    if (!has_type) {
        return -1 ; 
    }
    DType_Slots* dt_slots = (DType_Slots* )Mem_Malloc (sizeof (DType_Slots)) ; 
    if (dt_slots == NULL) {
        return -1 ; 
    }

    memset (dt_slots , 0 , sizeof (DType_Slots)) ; 
    Array_DTypeMeta* dtype_class = Mem_Malloc (sizeof (Array_DTypeMeta)) ; 
    if (dtype_class==NULL) {
        Mem_Free(dt_slots)  ;
        return -1;
    }
    static Array_DTypeMeta prototype = {
        .super = {
            .ob_base = {
                .ob_base = {
                    .ref_cnt = 1 ,
                    .tp_type = &ArrayDTypeMeta_Type
                },
                .size = 0 
            },
            .tp_basicsize = sizeof (Array_Descr) ,
            .tp_base = NULL ,
            .tp_name = NULL , // later 
        },
    }; 
    memcpy(dtype_class, &prototype, sizeof(Array_DTypeMeta));
    SET_TYPE(descr, (TypeObject *)dtype_class);
    printf("all is good ! \n") ; 

    return 0;
}
