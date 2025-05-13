#include "object.h"
#include "types.h"
#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_dtype.h"


#define INT_Name "Int"

static DType_Slots array_dtype_slots = {
    .get_fill_zero_loop = NULL ,
}; 

Array_DTypeMeta _ArrayDescr_MetaType = {
   .super = {
        .ob_base = {
            .ob_base = {
                    .ref_cnt = 1 ,
                    .tp_type = &TypeObject_Type 
            },
            .size = 0   
        },
        .tp_name = "dtype"  ,
   }, 
   .scalar_type = NULL ,
   .dt_slots = &array_dtype_slots 
};


