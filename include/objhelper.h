#ifndef OBJHELPER_H
#define OBJHELPER_H
#include <stddef.h>
// Macros for computing struct header sizes
#define HEADER_SIZE(struct_type, field_name) \
    offsetof(struct_type, field_name)

#define DEFINE_STRUCT_HEADER_SIZE(typedef_name, field_name) \
    enum { typedef_name##_HEADER_SIZE = HEADER_SIZE(typedef_name, field_name) }

#endif
