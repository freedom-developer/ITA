#ifndef QS_H
#define QS_H

enum {
    ET_8, ET_U8, ET_16, ET_U16, ET_32, ET_U32, ET_64, ET_U64
};

void quicksort(void *A, int p, int r, int type, int x);

#endif