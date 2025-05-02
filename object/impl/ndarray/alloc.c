#include "mem.h"


static inline void* 
_alloc (ssize_t nelem, ssize_t esz ,void* (*alloc)(ssize_t)){
    void* p = alloc (nelem * esz) ; 
    return p;
}

void* 
dim_alloc (ssize_t sz ){
    if (sz <2 ) {
        sz =2 ; 
    }
    return _alloc(sz , sizeof (ssize_t) , &Object_Malloc);
}
