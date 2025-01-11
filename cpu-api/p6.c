#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO); 
	    open("./p5.output", O_CREAT|O_WRONLY|O_APPEND, S_IRWXU);
        printf("write text from child!\n");
    } else {
        close(STDOUT_FILENO);
        open("./p5.output", O_CREAT|O_WRONLY|O_APPEND, S_IRWXU);
        sleep(1);
        printf("write text from parent!\n");
    }
    printf("\n");
    return 0;
}