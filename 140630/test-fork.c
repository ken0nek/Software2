/* test-fork.c */
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;

void task(int loop) {
    int i, j, tmp;
    for (i=0; i<loop; i++) {
        for (j=0; j<10000; j++) {
            tmp = shared_resource;
            tmp += 1;
            usleep(1);
            shared_resource = tmp;
        }
        printf("Process [%d]: loop = %d, count = %d / j = %d\n", getpid(), loop, i, tmp);
    }
}

int main() {
    pid_t pid;
    int loop1 = 10, loop2 = 20;

    task(10);
    printf("Process %d finished, return %d.\n", getpid(), shared_resource);
    pid = fork();
    if (pid == 0) {
        // child process
        task(loop2);
        printf("Process %d finished, return %d.\n", pid, shared_resource);
        exit(0);
    } else if (pid > 0) {
        // parent process
        int status;
        task(loop1);
        wait(&status);
        printf("Process %d finished, return %d.\n", pid, shared_resource);
    }
    return 0;
}
