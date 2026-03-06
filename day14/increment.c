#include <stdio.h>

void increment(int *arr,int size);

int main(){
    // Getting all the elements of array without using *(arr +1)
    int arr[] = {101,20,30,40,501,60,70};
    int size = sizeof(arr) / sizeof(arr[0]);
    increment(arr,size);

    return 0;
}

void increment(int *arr,int size) {
    int *ptr = arr;
    for (int i = 0; i<size;i++) {
        int *num = ptr +i;
        printf("%d. Element-> %d\n",i,*num);
    }
}
