#include <unistd.h>
#include <stdio.h>

typedef struct Block {
    size_t size;
    size_t free;
    struct Block *next;
}block_t;

#define HEADER_SIZE sizeof(block_t)

void* my_malloc(size_t size) {
    block_t *memory = (block_t*)sbrk(HEADER_SIZE + size);
    memory->size = size;
    memory->free = 0;
    memory->next = NULL;

    return (void*)(memory+1);
}

int main() {
    int *num = (int*)my_malloc(8);
    *num = 20;

    printf("Num-> %p\n",num);

    return 0;
}
