#ifndef ARRAYDESCR_H
#define ARRAYDESCR_H

#include "object.h"

enum _TYPECHAR {
    _SIGNEDLTR = 'i', 
};
enum _TYPES {
    _INT = 0 ,  
};

typedef struct  {
    Object_HEAD 
    TypeObject* typeobj ; 
    int type_num ; 
    unsigned long flags ; 
    ssize_t elsize ; 
    ssize_t alignment ; 
}Array_Descr ; 


#endif
