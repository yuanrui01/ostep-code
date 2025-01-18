#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* p = (int*) malloc(sizeof(int));
    *p = 123;
    return 0;
}