#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void ) { 
    char* src = "hello";
    char* dst;
    dst = strdup(src);
    if (dst != NULL) {
        printf("Duplicated string %s\n", dst);
        free(dst);
    }
    return 0;
}