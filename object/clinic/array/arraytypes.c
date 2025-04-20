#include "types.h"
#include "clinic/ndarrayobj.h"

Array_LagacyDescr INT_Descr = {
    .ad_base = {
        .ob_base = {
            .ref_cnt = 1 ,
            .tp_type = NULL 
        },
        .typeobj = &IntArrObject_Type ,
        .kind = _SIGNEDLTR ,  
        .type = _SIGNEDLTR , 
        .byteorder = '=',
        .flags = 0 ,
        .type_num = _INT ,
        .elsize = sizeof (int) , 
        .alignment = _Alignof(int) , 
        .hash = -1,
         

    },
}; 

Array_LagacyDescr* _buildin_descrs[] = {
    &INT_Descr
}; 
