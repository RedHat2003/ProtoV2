#ifndef OBJECT_IMPL_H
#define OBJECT_IMPL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Include/object.h"

ssize_t _Object_SIZE(TypeObject* tp);
ssize_t _Object_Var_SIZE(TypeObject* tp, ssize_t nitem);
void _Object_Init(Object* ob, TypeObject* tp);
void _Object_Var_Init(VarObject* vob, TypeObject* tp, ssize_t size);
VarObject* _Object_NewVar(TypeObject* tp , ssize_t nitem) ; 
void _Object_Dealloc (Object* op) ; 
#define Object_SIZE(tp) _Object_SIZE(tp)
#define Object_Var_SIZE(tp, n) _Object_Var_SIZE((tp), (n))
#define Object_Init(ob, tp) _Object_Init((ob), (tp))
#define Object_Var_Init(ob, tp, s) _Object_Var_Init((VarObject* )ob, (tp), (s))
#define Object_NewVar(type, tp, n) (type* )_Object_NewVar((tp), (n)) 
#define Object_Dealloc(op) _Object_Dealloc((Object* )op) ; 
#ifdef __cplusplus
}
#endif

#endif

