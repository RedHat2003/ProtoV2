#ifndef FLOATARROBJ_C_H
#define FLOATARROBJ_C_H

#include "Include/clinic/floatarrobj.h"
Object* floatarr_new(TypeObject* tp);
FloatArrObject* floatarr_alloc(ssize_t size);
FloatArrObject* FloatArr_New(ssize_t size);
void floatarr_dealloc (Object* op) ; 

#endif
