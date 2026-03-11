#include <unistd.h>
#include <stdio.h>

typedef struct Block {
    size_t size;
}block_t;

#define HEADER_SIZE sizeof(block_t)

void* my_malloc(size_t size) {
    block_t *memory = (block_t*)sbrk(HEADER_SIZE + size);
    memory->size = size;
    return (void*) (memory+1);
}

// Making an nuke function which will delete all the variables after a specified memory. NOTE: nuke function behaviour will not be same as free()
void nuke(void *pointer) {
    brk(pointer);
}

int main() {

    size_t numSize= 3 * sizeof(int);
    int *ptr = (int*)my_malloc(numSize);
    ptr[0] = 23;
    ptr[1] = 58;
    ptr[2] = 2;
    printf("Last break address -> %p\n",sbrk(0));
    printf("The memory address of *ptr is ->%p\n",ptr);
    printf("All the elements of *ptr\n");
    for (int i = 0;i<3;i++) {
        printf("Element %d->%d\n",i+1,ptr[i]);
    }
    nuke(ptr);
    printf("The memory address of *ptr is ->%p\n",ptr);

    return 0;
}
