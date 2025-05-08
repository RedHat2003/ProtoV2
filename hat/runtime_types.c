#include "include/objimpl.h"
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include <stdio.h>


int  wrap_legacy_types(Array_Descr* descr ) {
    int has_type = Get_ObjType(descr) == &ArrayDtype_Type ; 
    if (has_type) {
        return 1 ; 
    }
    return -1;
}
