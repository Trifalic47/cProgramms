#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>

#define ROWS 6
#define COLS 100

void readPath(char info[ROWS][COLS],char find[ROWS][COLS]);

int main() {
    char info[ROWS][COLS] = {"version","meminfo","swaps","mtd","cpuinfo","devices"};
    char find[ROWS][COLS] = {
    "Linux version",
    "MemTotal",
    "MemAvailable",
    "/dev/",
    "model name",
    "mtd"
};
    printf("Fetching information about your current system..\n");
    readPath(info,find);
    return 0;
}

void readPath(char info[ROWS][COLS],char find[ROWS][COLS]){
    for (int i = 0; i<6;i++) {
        char path[100]="/proc/";
        char *dest = info[i];
        strcat(path,dest);

        // Opening,closing and reading file data
        int fd = open(path,O_RDONLY);
        if (fd == -1) {
            printf("File '%s' not found!\n",path);
            return;
        }
        char buff[4096];
        size_t n;
        while((n=read(fd,buff,4096)) != 0) {
            for(int j=0;j<ROWS;j++) {
                char *locate = strstr(buff,find[j]);
                if (locate == NULL) {
                    continue;
                }else{
                    char filter[100];
                    sscanf(locate, "%*[^:]: %99[^\n]", filter);
                    printf("\n\n%s-> %s",find[j],filter);
                }
            }
            printf("\n");
        }
    }
}
