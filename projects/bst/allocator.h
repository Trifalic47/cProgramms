#include "bst.h"

#define HEADER_SIZE sizeof(block_t)

void* alloc(size_t size);
void free(void *ptr);
