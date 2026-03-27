#include <unistd.h>
#include <stdio.h>

int main() {
    chdir("/home/ascend");
    char buf[256];
    getcwd(buf, 256);
    printf("%s\n",buf);
}
