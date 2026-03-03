#include <stdio.h>

int main(){
    // Counting the frequency of only one number
    int arr[] = {1, 2, 3, 2, 1, 3, 4, 1};
    int num;
    printf("Enter the number of which to find the frequency:");
    scanf("%d",&num);

    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0 ; i < size; i++){
        if (arr[i] == num) {
            count++;
        }
    }

    printf("The number %d is found %d times\n",num,count);

    return 0;
}
