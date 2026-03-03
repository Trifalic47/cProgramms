#include <stdio.h>

int main(){
    int arr[] = {12,3,4,3,5,6,3,2,4,6,7,4,2,1,3,3,5,6,78,2,4,6,7,1,2,3,5,6,7,8,4,2,3,5,6,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int freq[size];

    for (int i=0;i<size;i++) {
        freq[i] = -1;
    }

    for (int i;i<size;i++) {
        int count = 1;
        for (int j=i+1;j<size;j++) {
            if(arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
            if (freq[i] != 0) {
                freq[i] = count;
            }
        }
    }

    printf("Element     |       Frequency\n");
    for (int i=0;i<size;i++) {
        if (freq[i] != 0){
                printf("%d      |       %d\n",arr[i],freq[i]);
            }
    }

    return 0;
}
