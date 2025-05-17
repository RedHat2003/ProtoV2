#include "clinic/tpobject.h"
#include "mem.h"
#include "refcount.h"

ssize_t
_Object_SIZE(TypeObject *tp)
{
    return tp->tp_basicsize;
}

ssize_t
_Object_Var_SIZE(TypeObject *tp, ssize_t nitems)
{
    return tp->tp_basicsize + nitems * tp->tp_itemsize;
}

ssize_t
_Object_refcnt(Object *ob)
{
    return ob->ref_cnt;
}

TypeObject *
_Get_ObjType(Object *ob)
{
    return ob->tp_type;
}

void
_SET_TYPE(Object *ob, TypeObject *tp)
{
    ob->tp_type = tp;
}

ssize_t
_Get_VarSize(VarObject *vob)
{
    return vob->size;
}

void
_SET_SIZE(VarObject *vob, ssize_t size)
{
    vob->size = size;
}

void
_Object_Init(Object *ob, TypeObject *tp)
{
    _NEWREF(ob);
    _SET_TYPE(ob, tp);
    _INCREF((Object *)tp);
}

void
_Object_Var_Init(VarObject *vob, TypeObject *tp, ssize_t nitems)
{
    _Object_Init((Object *)vob, tp);
    _SET_SIZE(vob, nitems);
}

VarObject *
_Object_NewVar(TypeObject *tp, ssize_t nitems)
{
    ssize_t total = _Object_Var_SIZE(tp, nitems);
    VarObject *vob = (VarObject *)Object_Malloc(total);
    if (!vob) {
        return NULL;
    }
    _Object_Var_Init(vob, tp, nitems);
    return vob;
}

Object *
_Object_New(TypeObject *tp)
{
    Object *ob = (Object *)Object_Malloc(_Object_SIZE(tp));
    if (!ob) {
        return NULL;
    }
    _Object_Init(ob, tp);
    return ob;
}

void
_Object_Dealloc(Object *ob)
{
    if (!ob) {
        return;
    }
    TypeObject *tp = ob->tp_type;
    if (tp && tp->tp_dealloc) {
        tp->tp_dealloc(ob);
    }
}

