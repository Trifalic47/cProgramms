#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd[2];
    if (pipe(fd) != 0) {
        perror("Error creating pipe");
    }
    if (fork() == 0) {
        // ------------ Child Process -------------------
        // ---- Command: echo new ---------------
        dup2(fd[1],1);

        close(fd[0]);
        close(fd[1]);

        char *args[] = {"echo","new",NULL};
        execvp("echo",args);
    }
    if (fork() == 0) {
        // ---- Another Child process ------
        // Write End -> Command -> base64
        dup2(fd[0],0);

        close(fd[0]);
        close(fd[1]);

        char *args[] = {"base64",NULL};
        execvp("base64",args);
    }
    // ----------- Parent Process -------
    // Wait for the both process to end

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
