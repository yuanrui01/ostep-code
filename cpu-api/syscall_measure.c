#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define ITERATIONS 1000000  // 设定循环次数以取平均值

int main() {
    char buffer[128];
    ssize_t bytesRead;

    struct timeval start, end;

    // 累加时间
    double total_time = 0;

    for (int i = 0; i < ITERATIONS; i++) {
        // 记录开始时间
        gettimeofday(&start, NULL);

        // 执行 0 字节读取的系统调用
        bytesRead = read(STDIN_FILENO, buffer, 0);

        // 记录结束时间
        gettimeofday(&end, NULL);

        // 计算每次系统调用的时间（单位：秒）
        double time_taken = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        total_time += time_taken;
    }

    // 计算平均时间（单位：微秒）
    double avg_time = total_time / ITERATIONS;

    printf("Average time taken for 0-byte read system call: %f microseconds\n", avg_time);

    return 0;
}
