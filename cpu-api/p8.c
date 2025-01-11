#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int pipefd[2];  // 管道文件描述符，pipefd[0] 是读端，pipefd[1] 是写端
    pid_t pid1, pid2;

    // 创建管道
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // 创建第一个子进程
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {  // 第一个子进程
        // 关闭管道的读端
        close(pipefd[0]);

        // 将标准输出重定向到管道的写端
        dup2(pipefd[1], STDOUT_FILENO);  // 将标准输出重定向到管道
        close(pipefd[1]);  // 关闭原始的写端文件描述符

        // 执行命令 echo "Hello"
        execlp("echo", "echo", "Hello world, my name is hpynos", NULL);
        perror("execlp failed");
        exit(1);
    }

    // 创建第二个子进程
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {  // 第二个子进程
        // 关闭管道的写端
        close(pipefd[1]);

        // 将标准输入重定向到管道的读端
        dup2(pipefd[0], STDIN_FILENO);  // 将标准输入重定向到管道
        close(pipefd[0]);  // 关闭原始的读端文件描述符

        // 执行命令 wc -l 计算行数
        execlp("wc", "wc", "-w", NULL);
        perror("execlp failed");
        exit(1);
    }

    // 父进程
    close(pipefd[0]);
    close(pipefd[1]);

    // 等待子进程结束
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
