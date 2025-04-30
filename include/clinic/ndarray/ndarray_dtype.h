#ifndef NDARRAY_DTYPE_H
#define NDARRAY_DTYPE_H

#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_descr.h"


extern Array_DTypeMeta _ArrayDescr_MetaType  ; 
#define ArrayDtype_Type ((TypeObject*)&_ArrayDescr_MetaType) 

#endif
