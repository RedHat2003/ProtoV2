#ifndef CORE_TYPES_H
#define CORE_TYPES_H

// A function that, when called, will wrap/initialize ALL your static types
typedef int (*TypeInitFunc)(void);

// Holds exactly one such init function
typedef struct {
    TypeInitFunc init_types;
} TypeInitRegistry;

#endif // CORE_TYPES_H

