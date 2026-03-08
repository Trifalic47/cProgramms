#include <stdio.h>
#include <stdlib.h>

void scan(int *num,char text[]);

int main() {

    int size;
    char text[] = "Enter the size of array to make:";

    scan(&size,text);

    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size ; i++) {
        printf("Enter the int at the index %d:",i);
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < size ; i++) {
        printf("The value at index %d is -> %d\n",i,arr[i]);
    }

    int newSize;
    scan(&newSize,"Enter the new size of the array:");
    int *ptrnew = (int*) realloc(arr,newSize * sizeof(int));
   if (ptrnew == NULL) {
        printf("Memory allocation failed\n");
        free(ptrnew);
        return 1;
    }

    for (int i = 0; i < newSize ; i++) {
        printf("The value at index %d is -> %d\n",i,ptrnew[i]);
    }

    free(ptrnew);

    return 0;
}

void scan(int *num,char text[]) {
    printf("%s",text);
    scanf("%d",num);
}
