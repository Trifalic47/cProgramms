#include <stdio.h>

int sum(int a,int b); // This is functions prototype

int main(){
    // Using this sum function
    int a,b;
    a = 10;
    b = 2;
    int total = sum(a,b);

    printf("The sum of %d and %d is %d\n",a,b,total);

    return 0;
}

int sum(int a,int b){ // This is functions definition
    return a+b;
}
