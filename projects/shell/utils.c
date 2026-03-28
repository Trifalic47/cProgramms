#include "utils.h"

void* my_malloc(size_t size) {
    block_t *memory = (block_t*)sbrk(HEADER_SIZE + size);
    memory->size = size;
    return (void*)(memory+1);
}

void my_free(void *ptr){
    block_t *memory = (block_t*)ptr-1;
    memory->free = 1;
}

void stringInput(char *str) {
    int i=0;
    char c;
    while (1) {
        read(0,&c,1);
        if (c == '\0' || c == '\n') {
            break;
        }
        str[i++] = c;
    }
    str[i] = '\0';
}

void print_int(int n) {
    char buf[20];
    int i = 0;
    if (n < 0) { write(1, "-", 1); n = -n; }
    if (n == 0) { write(1, "0", 1); return; }
    while (n > 0) { buf[i++] = '0' + (n % 10); n /= 10; }
    // reverse
    int l = 0, r = i - 1;
    while (l < r) { char tmp = buf[l]; buf[l++] = buf[r]; buf[r--] = tmp; }
    write(1, buf, i);
}
void print(const char *msg) {
    int len = 0;
    while (msg[len]) len++;
    write(1, msg, len);
}

int String_Length(char *str) {
    int len=0;
    while(str[len]) len++;
    return len;
}

void stringCopy(char *dest,char *src) {
    int src_len = String_Length(src);
    for (int i = 0;i <src_len;i++) {
        *(dest+i) = *(src+i);
    }
}

char* intToString(int num){
    char buff[12];
    if (num < 0) {
        write(1,"-",1);
    }else if(num == 0) {
        write(1,"0",1);
    }
    int i = 0;
    while (num>0) {
        buff[i++] = '0' + (num%10);
        num /= 10;
    }
    // Reversing
    int l = 0, r = i-1;
    while (l<r) {
        char tmp = buff[l];
        buff[l++] = buff[r];
        buff[r--] = tmp;
    }

    char *str = (char*)my_malloc(String_Length(buff) * sizeof(char));

    return str;
}

int stringCompare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) return 1;
        i++;
    }
    return str1[i] != str2[i];
}

void stripNewLine(char *str) {
    int len = String_Length(str);
    if (str[len-2] == '\n') str[len-2] = '\0';
}

void pkill(int pid) {
    kill(pid,SIGKILL);
}

void AP_KILL(int pid,int ppid) {
    kill(ppid,SIGKILL);
    kill(pid,SIGKILL);
}

void string_cat(char *dest, char *src) {
    int dest_size = String_Length(dest);
    int src_size = String_Length(src);
    int i = 0;
    while (i < src_size) {
        dest[dest_size + i] = src[i];
        i++;
    }
    dest[dest_size + i] = '\0';
}

int find(char *str, char *target) {
    int i = 0;
    while (target[i]) {
        char tempStr[2];
        tempStr[0] = target[i];
        tempStr[1] = '\0';

        if (stringCompare(str, tempStr) == 0) {
            return 0;
        }
        i++;
    }
    return -1;
}

int find_index(char *str,char *target) {
    int i = 0;
    while (target[i]) {
        if (str[0] == target[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

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
