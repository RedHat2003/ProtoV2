#include "clinic/capsule.h"
#include "clinic/tpobject.h"
#include "types.h"
TypeObject Capsule_Type = {
    .ob_base = {
        .ob_base = {
            .ref_cnt = 1 , 
            .tp_type = &TypeObject_Type ,
        },
        .size = 0 
    },
    .tp_name = "Capsule" , 
    .tp_basicsize = sizeof (CapsuleObj) ,
    // others later 

};
