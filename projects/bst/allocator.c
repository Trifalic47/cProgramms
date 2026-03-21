#include "allocator.h"

void* alloc(size_t size) {
    block_t *memory = (block_t*)sbrk(size+HEADER_SIZE);
    memory->size = size;
    return (void*)(memory+1);
}

void free(void *ptr) {
    block_t *block = (block_t *)ptr - 1;
    block->free = 1;
}
