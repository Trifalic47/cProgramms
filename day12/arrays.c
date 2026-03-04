#include <stdio.h>

int main(){
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i =0 ;i < size; i++) {
        arr[i] = i+1;
    }

    int *ptr = arr;
    printf("The memory address of the array is %p\n",ptr);

    return 0;
}
