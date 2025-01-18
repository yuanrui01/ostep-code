#include <stdio.h>

int main(void) {
    int* p = NULL;

    // trigger segmentation fault
    printf("null pointer to a int, val is %d", *p);
    return 0;
}