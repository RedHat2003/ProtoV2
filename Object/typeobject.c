#include "Include/clinic/tpobject.h"

TypeObject TypeObject_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 0 ,
            .tp_type = &TypeObject_Type
        },
        .size = 0 
    },
    .tp_name = "type"
};


