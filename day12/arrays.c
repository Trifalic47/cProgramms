#include <stdio.h>

void printContents(int *arr,int size);

int main(){
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i =0 ;i < size; i++) {
        arr[i] = i+1;
    }

    int *ptr = arr;
    printf("The memory address of the array is %p\n",ptr);

    printContents(arr,size);

    return 0;
}


void printContents(int *arr,int size){
    for (int i = 0 ;i < size;i++) {
        printf("%d\n",arr[i]);
    }
}
