#include "types.h"
#include "clinic/config.h"
#include "clinic/tpobject.h"

TypeObject Config_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 1 ,
            .tp_type = &TypeObject_Type
        } , 
        .size = 0
    } ,
    .tp_name = "Config" ,
    .tp_basicsize = sizeof(Config) , 
    .tp_itemsize = 0 ,
};


