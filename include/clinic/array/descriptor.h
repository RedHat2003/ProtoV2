#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H 
#include "object.h"
#include "clinic/ndarrayobj.h"


extern Array_DTypeMeta _ArrayDescr_MetaType ; 
#define ArrayDescr_MetaType ((TypeObject*)&_ArrayDescr_MetaType)
#endif
