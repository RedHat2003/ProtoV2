#ifndef CORE_FREELSIT_STATE_H 
#define CORE_FREELSIT_STATE_H

#include <sys/types.h>

struct _freelist {
    void* freelist  ;
    ssize_t size ; 
}; 

typedef struct {
    struct _freelist tuple_iters ; 
}_Freelists;

#endif
