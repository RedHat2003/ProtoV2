#include "types.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/ndarray_dtype.h"

Array_Descr INT_Descr = {
    .ob_base = {
        .ref_cnt = 1 ,
        .tp_type = &ArrayDtype_Type  
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
