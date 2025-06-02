#ifndef CONFIG_H 
#define CONFIG_H
#include "object.h"


typedef struct confing {
    Object_HEAD 
    unsigned int say_hi :1 ;  
    unsigned int complement:31 ; 
}Config;

#endif 





