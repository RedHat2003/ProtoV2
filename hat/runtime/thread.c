#include <internal/core_thread.h>


unsigned long 
Thread_get_thread_ident() {
   volatile pthread_t threadid ; 
   threadid = pthread_self () ; 
   return (unsigned long )threadid;
}


