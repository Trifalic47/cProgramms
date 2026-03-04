#include <stdio.h>

int main(){
    int age = 14;
    int *ptr = &age;

    printf("The memory address of the age is %p and value is %d\n",ptr,*ptr);

    return 0;
}
