#include "object.h"
#include "types.h"
#include "clinic/ndarrayobj.h"

Array_DTypeMeta _ArrayDescr_MetaType = {
   .super = {
        .ob_base = {
            .ob_base = {
                    .ref_cnt = 1 ,
                    .tp_type = &TypeObject_Type 
            },
            .size = sizeof (Array_Descr) 
        },
        .tp_name = "dtype"  ,
   }, 
   .singleton = NULL , 
   .type_num = -1 ,
   .scalar_type = NULL ,
   .flags = 1 << 1 
};


