#include "types.h"
#include "clinic/ndarrayobj.h"
#include "internal/array_internals/_core/descriptor.h"

Array_Descr INT_Descr = {
    .ob_base = {
        .ref_cnt = 1 ,
        .tp_type = ArrayDescr_MetaType 
    },
    .typeobj = NULL ,
    .flags = 0 ,
    .type_num = _INT ,
    .elsize = sizeof (int) , 
    .alignment = _Alignof(int) , 
         

}; 

// NOTE: If new types are added to _buildin_descrs[], 
// increment NTYPES_LEGACY accordingly to reflect the total count.
Array_Descr* _buildin_descrs[] = {
    &INT_Descr
}; 
