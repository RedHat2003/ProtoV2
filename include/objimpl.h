/* object_impl.h */
#ifndef OBJECT_IMPL_H
#define OBJECT_IMPL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>     /* size_t / ssize_t */
#include "object.h"     /* Object, VarObject, TypeObject */

/*── Prototypes ───────────────────────────────────────────────────────────*/

ssize_t    _Object_SIZE       (TypeObject *tp);
ssize_t    _Object_Var_SIZE   (TypeObject *tp, ssize_t nitems);
ssize_t    _Object_refcnt     (Object *ob);
TypeObject*_Get_ObjType       (Object *ob);
void       _SET_TYPE          (Object *ob, TypeObject *tp);
ssize_t    _Get_VarSize       (VarObject *vob);
void       _SET_SIZE          (VarObject *vob, ssize_t size);

void       _Object_Init       (Object *ob, TypeObject *tp);
void       _Object_Var_Init   (VarObject *vob, TypeObject *tp, ssize_t nitems);

VarObject* _Object_NewVar     (TypeObject *tp, ssize_t nitems);
Object*    _Object_New        (TypeObject *tp);
void       _Object_Dealloc    (Object *ob);

/*── Convenience macros (wrap the underscored API) ───────────────────────*/

#define Object_SIZE(tp)         _Object_SIZE((tp))
#define Object_Var_SIZE(tp,n)   _Object_Var_SIZE((tp),(n))
#define Object_refcnt(ob)       _Object_refcnt((Object *)(ob))
#define Get_ObjType(op)         _Get_ObjType((Object *)(op))

#define SET_TYPE(ob,tp)         _SET_TYPE((Object *)(ob),(tp))
#define Get_VarSize(vob)        _Get_VarSize((VarObject *)(vob))
#define SET_SIZE(vob,sz)        _SET_SIZE((VarObject *)(vob),(sz))

#define Object_Init(ob,tp)      _Object_Init((Object *)(ob),(tp))
#define Object_Var_Init(vob,tp,n) \
                                _Object_Var_Init((VarObject *)(vob),(tp),(n))

#define Object_NewVar(type,tp,n) ((type *)_Object_NewVar((tp),(n)))
#define Object_New(type,tp)      ((type *)_Object_New((tp)))
#define Object_Dealloc(ob)       _Object_Dealloc((Object *)(ob))


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* OBJECT_IMPL_H */

