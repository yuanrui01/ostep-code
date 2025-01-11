#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // printf("child pre execvp ls\n");
        // char *myargs[2];
        // myargs[0] = strdup("ls");
        // myargs[1] = "-l";
        // myargs[2] = NULL;
        // execvp(myargs[0], myargs);

        // printf("v10 child pre execlp ls\n");
        // execlp("ls", "ls", "-l", NULL);

        // printf("child pre execv ls\n");
        // char *myargs[2];
        // myargs[0] = strdup("/bin/ls");
        // myargs[1] = "-l";
        // myargs[2] = NULL;
        // execv(myargs[0], myargs);

        // printf("(pid: %d)v11 child pre execl ls\n", (int)getpid());
        // execl("/bin/ls", "ls", "-l", NULL);
        sleep(1);
        printf("(pid: %d)v11 child pre execl ls\n", (int)getpid());
        int wc = wait(NULL);
        printf("(pid: %d)after child wait.\n", (int) getpid());
    } else {
        // int wc = wait(NULL);
        // printf("(pid: %d)parent end. wc is : %d\n", (int)getpid(), wc);
        int status;
        waitpid(rc, &status, 0);
        printf("(pid: %d)parent end.\n", (int)getpid());
    }
    return 0;
}
