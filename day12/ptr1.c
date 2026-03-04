#include <stdio.h>

int main(){
    // We are going to study about the pointers in C
    // NOTE: It is one of the most important concept in C programming.Most of the C programs uses the concepts of pointers

    int age = 14;
    int *ptrToAge = &age;
    printf("%p\n",ptrToAge);

    return 0;
}
