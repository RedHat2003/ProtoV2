#include "types.h"
#include "clinic/ndarrayobj.h"
#include "internal/array_internals/_core/descriptor.h"

Array_LagacyDescr INT_Descr = {
    .ad_base = {
        .ob_base = {
            .ref_cnt = 1 ,
            .tp_type = ArrayDescr_MetaType 
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

// NOTE: If new types are added to _buildin_descrs[], 
// increment NTYPES_LEGACY accordingly to reflect the total count.
Array_LagacyDescr* _buildin_descrs[] = {
    &INT_Descr
}; 
