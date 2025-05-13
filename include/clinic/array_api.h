#ifndef ARRAY_API_H
#define ARRAY_API_H

#include "object.h"
#include "clinic/ndarrayobj.h"



Object* 
Array_New (
        TypeObject* subtype, int nd , ssize_t const* dims , int type_num ,
        ssize_t const* strides ,void* data, int flags,
        Object* obj) ; 

Array_Descr* 
Array_DescrFromType(int Type) ; 

#endif
