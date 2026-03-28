#include "utils.h"
#include <stdlib.h>

int main() {
    while (1) {
        pid_t process = fork();
        if (process == 0 ) {
            char cmd[100];
            print("Trishell:");
            stringInput(cmd);
            if (stringCompare(cmd,"exit") == 0) {
                AP_KILL(getpid(),getppid());
            } else if (stringCompare(cmd,"") == 0) {
                stringCopy(cmd,"printf " "");
            } else if (find("|",cmd) == 0) {
                int pipefd[2];
                int idx = find_index("|",cmd);
                char readText[sizeof(cmd)/sizeof(cmd[0])];
                for (int i = 0;i<idx;i++) {
                    readText[i] = cmd[i];
                }
                exit(0);
            }

            char cmd_blocks[100][100];
            int word = 0, ch = 0, i = 0;
            while (cmd[i]) {
                if (cmd[i] == ' ') {
                    cmd_blocks[word][ch] = '\0';
                    word++;
                    ch = 0;
                } else {
                    cmd_blocks[word][ch++] = cmd[i];
                }
                i++;
            }
            cmd_blocks[word][ch] = '\0';
            char *envp[] = {NULL};
            char binary[100] = "/usr/bin/";
            string_cat(binary,cmd_blocks[0]);
            char *argv[100];
            for (int i = 0; i <= word; i++) {
                argv[i] = cmd_blocks[i];
                 }
            if (stringCompare(argv[0],"cd") == 0) {
                chdir(argv[1]);
            }
            argv[word + 1] = NULL;
            execve(binary,argv,envp);
    } else {
        waitpid(process, NULL, 0);
}
}
    return 0;
}
