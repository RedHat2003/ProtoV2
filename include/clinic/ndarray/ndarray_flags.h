#ifndef ARRAYFLAGS_H
#define ARRAYFLAGS_H

// Individual flags: one bit per property
#define ARRAY_C_CONTIGUOUS    0x0001  // 0000 0000 0000 0001 (bit 0)
#define ARRAY_WRITEABLE       0x0002  // 0000 0000 0000 0010 (bit 1)
#define ARRAY_ALIGNED         0x0004  // 0000 0000 0000 0100 (bit 2)

// Combined flags
#define ARRAY_BEHAVED (ARRAY_ALIGNED | \
                       ARRAY_WRITEABLE)

// Default flags: behaved + C order
#define ARRAY_DEFAULT (ARRAY_BEHAVED | \
                       ARRAY_C_CONTIGUOUS)

// (Optional) later you can define Fortran order
// #define ARRAY_F_CONTIGUOUS  0x0008  // 0000 0000 0000 1000 (bit 3)


#endif 

