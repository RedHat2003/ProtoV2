#ifndef HANDLER_H 
#define HANDLER_H

#include "object.h"     

char* currnet_handler_name(void) ; 
extern Object* current_handler ; 
int default_handler_init (void) ; 


void* DataMem_UserNEW (ssize_t , Object* ) ;
#endif
