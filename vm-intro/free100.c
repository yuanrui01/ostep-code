#include <stdio.h>
#include <stdlib.h>

int main(void)  {
    int* p = (int*) malloc(sizeof(int) * 100);

    for (int i = 0; i < 100; ++i) {
        p[i] = i;
    }

    free(p);
    printf("print the 99th after free, 99th: %d\n", p[99]);
    return 0;
}