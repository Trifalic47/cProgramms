#include <unistd.h>

typedef struct Header {
    size_t size;
    int free;
}block_t;

#define HEADER_SIZE sizeof(block_t)

void* my_malloc(size_t size);
void my_free(void *ptr);
void stringInput(char *str);
int String_Length(char *str);
void stringCopy(char *dest,char *src);
void print_int(int n);
void print(const char *msg);
char* intToString(int i);
int stringCompare(char *str1,char *str2);
void stripNewLine(char *str);
