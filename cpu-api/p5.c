#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int x = 0;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x += 2;
        printf("hello, i am a child, x is %d\n", x);
    } else {
        x += 5;
        printf("helo, i am parent, x is %d\n", x);
    }
    return 0;
}