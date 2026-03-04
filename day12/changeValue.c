#include <stdio.h>

int main(){
    int num = 15;

    // Making an pointer which will hold the memory address of the integer num
    int *numPointer = &num;
    printf("The memory address of the variable num is %p and its value is %d\n",numPointer,num);

    // Changing the value of num by modifying the pointer
    *numPointer = 200;
    printf("The memory address of the variable num is %p and its value is %d\n",numPointer,num);


    return 0;
}
