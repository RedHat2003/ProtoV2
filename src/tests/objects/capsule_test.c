#include "clinic/capsule.h"
#include "clinic/tpobject.h"
#include "objimpl.h"

#include <stdio.h>
#include "mem.h"
typedef struct any {
    int a ; 
}Any ; 

static Any s = {
    .a = 2003  
} ; 

int main (void) {
    CapsuleObj* capsule1 = (CapsuleObj* )Capsule_New(&s, "capsule1") ; 

    TypeObject* capsule1_type = Get_ObjType(capsule1) ; 

    // checking the type of capsule //
    
    printf (
            "the type of capsule1 is : %s\n",
            capsule1_type->tp_name  
        );

    // data from the capsule // 
    int a_capsule1 =  ((Any* )capsule1->pointer)->a ; 

    printf (
            "a from the capsule1 is : %d\n",
            a_capsule1
        );

    Object_Free (capsule1)  ; 

    return 0;
}
