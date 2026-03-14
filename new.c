#include <stdio.h>
#include <unistd.h>

typedef struct Block {
    size_t size;
}block_t;

#define HEADER_SIZE sizeof(block_t)

void* my_alloc(size_t size);
void intInput(int *num,char *text);
void arrInput(int *arr,int size);
void arrPrint(int *arr,int size);

int main() {
    int size;
    char text[] = "Enter the size in bytes that you want to allocate:";
    intInput(&size,text);
    int *ptr = my_alloc(size * sizeof(int));
    arrInput(ptr,size);
    arrPrint(ptr,size);
    return 0;
}

void* my_alloc(size_t size) {
    block_t *mem = (block_t*)sbrk(HEADER_SIZE + size);
    mem->size = size;
    return mem+1;
}

void intInput(int *num,char *text) {
    printf("%s",text);
    scanf("%d",num);
}

void arrInput(int *arr,int size) {
    for (int i = 0;i<size;i++) {
        printf("Enter the value at the index %d:",i);
        scanf("%d",&arr[i]);
    }
}

void arrPrint(int *arr,int size) {
    for (int i =0; i<size;i++) {
        printf("The value at the index %d is -> %d\n",i,arr[i]);
    }
}
