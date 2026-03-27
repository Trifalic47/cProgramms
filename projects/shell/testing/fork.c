#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("This is an child process and pid is: %d\n",getpid());
    }else if (pid > 0) {
        printf("This is the parent process and the pid is: %d\n",getpid());
    }else {
        printf("Error while creating child process");
    }
    return 0;
}
