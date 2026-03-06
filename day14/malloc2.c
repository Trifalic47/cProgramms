#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter how much numbers do you want to store:");
    scanf("%d",&size);

    int *mem = (int *)malloc(size * sizeof(int));
    if (mem == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0;i< size;i++) {
        printf("Enter the number %d->",i+1);
        scanf("%d",&mem[i]);
    }
    printf("Elements of mem:\n");
    for (int i = 0;i < size ;i++) {
        printf("Element %d->%d\n",i+1,mem[i]);
    }
    free(mem);
    mem = NULL;

    return 0;
}
