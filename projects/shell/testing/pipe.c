#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char* msg1 = "hello, world #1";
    int MSGSIZE = strlen(msg1) * sizeof(char);
    char inbuf[MSGSIZE];
    int pipefd[2];

    if (pipe(pipefd) != 0) {
        exit(1);
    }

    /* continued */
    /* write pipe */

    write(pipefd[1], msg1, MSGSIZE);

    for (int i = 0; i < 1; i++) {
    /* 1. Read from the pipe */
    ssize_t nbytes = read(pipefd[0], inbuf, MSGSIZE - 1);
    if (nbytes < 0) {
        perror("read");
        break;
    }
    inbuf[nbytes] = '\0'; // Ensure the string is null-terminated

    /* 2. Prepare arguments for execve */
    // execve needs an array of char pointers: {path, arg1, arg2, ..., NULL}
    char *args[] = {"/usr/bin/nvim", inbuf, NULL};
    char *envp[] = {NULL};

    execve("/usr/bin/nvim", args, envp);

    /* If execve returns, it failed */
    perror("execve");
}
    return 0;
}
