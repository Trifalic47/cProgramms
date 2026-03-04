#include <stdio.h>

int main(){
    int age = 20;
    int *ptr = &age;

    int **ptr2 = &ptr;
    printf("The memory address of ptr is %p and ptr2 is %p and the value of age is %d\n",ptr,ptr2,**ptr2);

    return 0;
}
