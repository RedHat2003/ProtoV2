#ifndef CORE_FREELSIT_STATE_H 
#define CORE_FREELSIT_STATE_H

#include <sys/types.h>

#  define Tuple_MAXSAVESIZE 20    
#  define tuple_MAXFREELIST 10 

struct _freelist {
    void* freelist  ;
    ssize_t size ; 
}; 

typedef struct {
    struct _freelist tuples[Tuple_MAXSAVESIZE] ; 
    struct _freelist tuple_iters ; 
}_Freelists;

#endif
