#include <stdio.h>

int main(){
    int arr[] = {2,4,5,23,12,4,5,6,7,4,3,3,5,7,8,9,5,3,2,2,4,6,7,8,9,7,6,45,3,4,5,6,7,87,6,5,4,3,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int freq[size];

    for (int i =0;i < size;i++) {
        freq[i] = -1;
    }

    // Counting the frequency
    for (int i = 0; i<size;i++) {
        int count = 1;
        for (int j = i+1;j<size;j++) {
            if (arr[j] == arr[i]) {
                freq[j]= 0;
                count ++;
            }
             if (arr[i]!=0) {
                freq[i] = count;
            }
        }
    }

    printf("Element | Frequency\n");
        for (int i = 0; i < size; i++) {
            if (freq[i] != 0) {
                printf("   %d       |      %d\n", arr[i], freq[i]);
            }
        }


    return 0;
}
