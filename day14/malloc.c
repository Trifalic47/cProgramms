#include <stdlib.h>  // required for malloc and free
#include <stdio.h>

int main() {
    int n = 5;
    int *ptr = (int *)malloc(n * sizeof(int));  // allocate memory for 5 ints

    ptr[0] = 10;  // use it exactly like an array
    ptr[1] = 20;

    printf("%d\n",ptr[0]);
    free(ptr);    // release memory
    ptr = NULL;   // safety
    return 0;
}
