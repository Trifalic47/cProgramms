#include<unistd.h>
#include <string.h>
#include <fcntl.h>

void cat(char *filepath);
void print(char *text);

int main(int argc,char *argv[]) {
    cat(argv[1]);
    return 0;
}

void print(char *text) {
    write(1,text,strlen(text));
}

void cat(char *filepath) {
    int fd = open(filepath,O_RDONLY);
    if (fd == -1) {
        print("File not found\n");
        return;
    }
    char buff[4096];
    ssize_t n;
    while ((n=read(fd,buff,4096)) > 0) {
        write(1,buff,n);
    }
    close(fd);
    print("\n");
}
