#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "quicksort.h"

#define type2size(type) (1 << (type/2))
#define ARRAY(a, i, type) (void *)(a + i * type2size(type))
#define CMP(ap, bp, type) (*(type *)(ap) <= *(type *)(bp))
#define CMP_R(ap, bp, type) (*(type *)(ap) >= *(type *)(bp))
#define EXCHANGE_VAL(ap, bp, type) \
do {    \
    type tmp = *(type *)(ap); \
    *(type *)(ap) = *(type *)(bp);  \
    *(type *)(bp) = tmp;    \
} while (0)

static void set_val(void *a, void *val, int type)
{
    memcpy(a, val, type2size(type));
}

static void exchange_val(void *a, void *b, int type)
{
    switch (type / 2) 
    {
    case 0: EXCHANGE_VAL(a, b, int8_t); break;
    case 1: EXCHANGE_VAL(a, b, int16_t); break;
    case 2: EXCHANGE_VAL(a, b, int32_t); break;
    case 3: EXCHANGE_VAL(a, b, int64_t); break;
    default:  break;
    }
}

static int default_cmp_d(void *a, void *b, int type, int x)
{
    switch (type)
    {
    case ET_8:      return (x == 0 ? CMP(a, b, int8_t) : CMP_R(a, b, int8_t));
    case ET_U8:     return (x == 0 ? CMP(a, b, uint8_t) : CMP_R(a, b, uint8_t));
    case ET_16:      return (x == 0 ? CMP(a, b, int16_t) : CMP_R(a, b, int16_t));
    case ET_U16:     return (x == 0 ? CMP(a, b, uint16_t) : CMP_R(a, b, uint16_t));
    case ET_32:      return (x == 0 ? CMP(a, b, int32_t) : CMP_R(a, b, int32_t));
    case ET_U32:     return (x == 0 ? CMP(a, b, uint32_t) : CMP_R(a, b, uint32_t));
    case ET_64:      return (x == 0 ? CMP(a, b, int64_t) : CMP_R(a, b, int64_t));
    case ET_U64:     return (x == 0 ? CMP(a, b, uint64_t) : CMP_R(a, b, uint64_t));
    
    default:
        return 0;
    }
}


static int partition(void *A, int type, int p, int r, int d)
{
    int i, j, k;
    void *x;

    k = rand() % (r - p + 1) + p;

    x = calloc(1, type2size(type));
    exchange_val(ARRAY(A, r, type), ARRAY(A, k, type), type);
    set_val(x, ARRAY(A, r, type), type);

    i = p - 1;
    for (j = p; j < r; j++) {
        if (default_cmp_d(ARRAY(A, j, type), x, type, d)) {
            i++;
            exchange_val(ARRAY(A, j, type), ARRAY(A, i, type), type);
        }
    }
    i++;
    exchange_val(ARRAY(A, i, type), ARRAY(A, r, type), type);

    free(x);

    return i;
}


void quicksort(void *A, int p, int r, int type, int x)
{
    if (type < ET_8 || type > ET_U64) {
        fprintf(stderr, "Argument type invlaid\n");
    }

    srand(time(NULL));
    if (p < r) {
        int q = partition(A, type, p, r, x);
        quicksort(A, p, q - 1, type, x);
        quicksort(A, q + 1, r, type, x);
    }
}

