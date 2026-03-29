#include "utils.h"

void execute_pipe_manual(char *cmd) {
    int pipefd[2];
    int idx = find_index("|", cmd);
    if (idx == -1) return;

    char cmd1_str[256] = {0};
    char cmd2_str[256] = {0};

    int k = 0;
    while (k < idx) {
        cmd1_str[k] = cmd[k];
        k++;
    }
    k--;
    while (k >= 0 && (cmd1_str[k] == ' ' || cmd1_str[k] == '\t')) {
        cmd1_str[k] = '\0';
        k--;
    }
    cmd1_str[k + 1] = '\0';

    int j = 0;
    int start = idx + 1;
    while (cmd[start] == ' ' || cmd[start] == '\t') start++;
    for (int i = start; cmd[i] != '\0'; i++) {
        cmd2_str[j++] = cmd[i];
    }
    cmd2_str[j] = '\0';

    if (pipe(pipefd) != 0) {
        print("Pipe failed\n");
        return;
    }

    if (fork() == 0) {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);

        char path1[128] = "/usr/bin/";
        string_cat(path1, cmd1_str);

        char *argv1[] = {path1, NULL};
        char *envp[] = {NULL};

        execve(path1, argv1, envp);
        exit(1);
    }

    if (fork() == 0) {
        dup2(pipefd[0], 0);
        close(pipefd[1]);
        close(pipefd[0]);

        char path2[128] = "/usr/bin/";
        string_cat(path2, cmd2_str);

        char *argv2[] = {path2, NULL};
        char *envp[] = {NULL};

        execve(path2, argv2, envp);
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
}
