#include "clinic/tpobject.h"
#include "object.h"
#include "mem.h"
#include "refcount.h"


ssize_t 
_Object_SIZE(TypeObject* tp) {
    return tp->tp_basicsize;
}
ssize_t 
_Object_refcnt (Object* ob) {
    return ob->ref_cnt;
}
ssize_t
_Object_Var_SIZE(TypeObject* tp, ssize_t nitem) {
    ssize_t size = _Object_SIZE(tp);
    size += nitem * tp->tp_itemsize;
    return size;
}


TypeObject*
_Get_ObjType(Object* ob){
    TypeObject* tp = ob->tp_type ; 
    return tp;
}

#define TYPE_INCREF(tp)  _INCREF((Object *)(tp))

void 
_SET_TYPE(Object* ob, TypeObject* tp) {
    ob->tp_type = tp;
}

void 
_SET_SIZE(VarObject* vob, ssize_t size) {
    vob->size = size;
}



/*-- helpers --*/

void _Object_Init(Object *ob, TypeObject *tp)
{
    _NEWREF(ob);        /* 1️⃣ ابدأ بعدّاد = 1 للكائن الجديد */
    _SET_TYPE(ob, tp);  /* 2️⃣ ثبّت نوعه */
    TYPE_INCREF(tp);    /* 3️⃣ زد عدّاد النوع نفسه */
}









void 
_Object_Var_Init(VarObject* vob, TypeObject* tp, ssize_t size) {
    _Object_Init((Object*)vob, tp);
    _SET_SIZE(vob, size);
}

VarObject* 
_Object_NewVar(TypeObject* tp , ssize_t nitem) {
    VarObject* vob ; 
    const ssize_t size = _Object_Var_SIZE(tp , nitem) ; 
    vob = (VarObject* )Object_Malloc(size); 
    if (vob ==NULL) {
        return NULL;
    }
    _Object_Var_Init(vob , tp , nitem) ; 
    return vob;
}

void 
_Object_Dealloc (Object* op) {
    TypeObject* type = op->tp_type ;
    destructor dealloc = type->tp_dealloc ; 
    (*dealloc)(op) ; 
}

ssize_t 
_Get_VarSize(VarObject* vob) {
    return vob->size;
}

