#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* p = (int*) malloc(sizeof(int) * 100);

    free(p + 44);

    return 0;
}