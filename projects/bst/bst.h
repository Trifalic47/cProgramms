#include <unistd.h>
#include <ctype.h>
#include <string.h>

typedef struct Block {
    size_t size;
    int free;
}block_t;

void int_input(int *num,char *text);
void print(char *str);


