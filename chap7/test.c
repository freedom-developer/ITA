#include "quicksort.h"

#include <stdio.h>
#define ARRAY_SIZE(A) (sizeof(A) / sizeof(A[0]))

int main(int argc, char **argv)
{
    int i;
    char a[] = {'w', 'u', 's', 'h', 'e', 'n', 'g', 'b', 'a', 'n', 'g'};

    for (i = 0; i < ARRAY_SIZE(a); i++) {
        printf("%c ", a[i]);
    }
    printf("\nafter sort:\n");
    quicksort(a, 0, ARRAY_SIZE(a)-1, ET_8, 1);

    for (i = 0; i < ARRAY_SIZE(a); i++) {
        printf("%c ", a[i]);
    }
    printf("\n");

    return 0;
}