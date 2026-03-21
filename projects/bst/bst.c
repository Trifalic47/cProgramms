#include "bst.h"
#include "utils.h"

void print(char *str) {
    size_t size = strlen(str);
    write(1,str,size);
}

void int_input(int *num, char *text) {
    char buf[12];
    print(text);
    int bytes = read(0, buf, sizeof(buf) - 1);
    buf[bytes - 1] = '\0';  // strip the newline

    *num = 0;
    for (int i = 0; buf[i] != '\0'; i++) {
        *num = *num * 10 + (buf[i] - '0');
    }
    char str[12];
    int_to_str(*num,str);
    print(str);
    print("\n");
}
