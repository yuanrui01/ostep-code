#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* arr = (int*) malloc(sizeof(int) * 100);
    arr[100] = 0;
    return 0;
}