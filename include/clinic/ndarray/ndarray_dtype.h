#ifndef NDARRAY_DTYPE_H
#define NDARRAY_DTYPE_H

#include "objimpl.h"
#include "clinic/ndarrayobj.h"
#include "clinic/ndarray/ndarray_descr.h"

// Signature for legacy zero‐fill loops (simplified)
typedef int (ArrayMethod_GetTraverseLoop)(void);

// Slots table for a dtype: currently only zero‐fill, but extendable
typedef struct {
    ArrayMethod_GetTraverseLoop *get_fill_zero_loop;
} DType_Slots;

// The singleton meta‐type for Array_Descr objects
extern Array_DTypeMeta _ArrayDescr_MetaType;

// Convenience alias for the Array_Descr type object
#define ArrayDtype_Type  ((TypeObject *)&_ArrayDescr_MetaType)

/**
 * DType
 *
 * Convert a descriptor to its associated DTypeMeta.
 *
 * @param descr  Pointer to an Array_Descr instance.
 * @return       Pointer to the corresponding Array_DTypeMeta.
 */
static inline Array_DTypeMeta *
DType(const Array_Descr *descr)
{
    return (Array_DTypeMeta *)Get_ObjType((Object *)descr);
}

/**
 * DT_Slot
 *
 * Fetch the slots table for a given DTypeMeta.
 *
 * @param dtype  Pointer to an Array_DTypeMeta.
 * @return       Pointer to its DType_Slots.
 */
static inline DType_Slots *
DT_Slot(const Array_DTypeMeta *dtype)
{
    return (DType_Slots *)dtype->dt_slots;
}

/**
 * DT_SLOT_FROM_DESCR
 *
 * Get the slots table directly from a descriptor.
 */
#define DT_SLOT_FROM_DESCR(descr) \
    DT_Slot(DType(descr))

#endif  // NDARRAY_DTYPE_H

