#ifndef INTARROBJ_C_H
#define INTARROBJ_C_H

#include "Include/clinic/intarrobj.h"
Object* intarr_new(TypeObject* tp);
IntArrObject* intarr_alloc(ssize_t size);
IntArrObject* IntArr_New(ssize_t size);
void intarr_dealloc (Object* op) ; 
#endif
