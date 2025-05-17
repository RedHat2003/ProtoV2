#include <stdlib.h>
#include <clinic/ndarray/ndarray_alloc.h>

static inline void* 
_alloc(size_t nelem, size_t esz, void* (*alloc)(size_t)) {
    return alloc(nelem * esz);
}

static inline void 
_free(void* ptr, size_t nelem, void (*dealloc)(void*)) {
    (void)nelem;
    dealloc(ptr);
}

void* 
dim_alloc(size_t sz) {
    if (sz < 2) {
        sz = 2;
    }
    return _alloc(sz, sizeof(size_t), &malloc);
}

static inline void* 
default_malloc(void* ctx, ssize_t size) {
    (void)ctx;
    if (size <= 0) return NULL;
    return malloc((size_t)size);
}

static inline void 
default_free(void* ctx, void* ptr, ssize_t size) {
    (void)ctx;
    _free(ptr,size , &free);
}

DataMem_Handler default_handler = {
    .name = "default_handler",
    .allocator = {
        .ctx = NULL,
        .malloc = default_malloc,
        .free = default_free
    }
};

