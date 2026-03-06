#include <stdio.h>

void memoryAddresses(int *arr,int size);

int main(){
    // Pointers arithmetic in C programming language
    int numbers[4] = {10,20,30,40};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    memoryAddresses(numbers,size);
    return 0;
}

void memoryAddresses(int *arr,int size){
    int *ptr = arr;
    printf("Memory address of the numbers array-> %p\n",ptr);

    for (int i = 0;i<size;i++) {
        int num = *(ptr + i);
        printf("%d. Pointer Value: %d\n",i+1,num);
    }

}
