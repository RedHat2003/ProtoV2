// test_clinic_headers.c
#include "clinic/array_api.h"
#include "clinic/capsule.h"
#include "clinic/ndarrayobj.h"
#include "clinic/tpobject.h"
#include "clinic/tupleobj.h"

// Subheaders inside ndarray/
#include "clinic/ndarray/ndarray_descr.h"
#include "clinic/ndarray/ndarray_dtype.h"
#include "clinic/ndarray/ndarray_flags.h"
#include "clinic/ndarray/ndarray_helpers.h"

// Internal "header-only" ones (not part of public interface, but still in clinic/)
#include "clinic/ndarray/_src/dtypemeta.h"
#include "clinic/ndarray/_src/handler.h"

int main(void) {
    return 0;
}

