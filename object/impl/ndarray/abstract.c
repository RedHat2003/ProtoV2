#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/array_api.h"


Array_DTypeMeta Array_IntAbstractSType = {
    .super = {
        .ob_base = {
            .ob_base = {
                .ref_cnt = 1 , 
                .tp_type = &ArrayDTypeMeta_Type,
            },
            .size =  0 
        },
        .tp_name = "dtypes._IntegerAbstractDType" ,
        .tp_base = &ArrayDtype_Type,
        .tp_basicsize = sizeof (Array_Descr) 
    },
    .type_num = -1 
};
