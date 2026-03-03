#include <stdio.h>

int main(){
    // Printing the top 2 most frequent numbers in added in the array/list of numbers
    // We will use the topics like - 1d Arrays,input,loops(for)
    // NOTE: For practice we will also print the frequency of the numbers which will more strengthen our logic

    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int arr[size];
    int freq[size];

    for (int i = 0;i<size;i++){
        printf("Enter the number %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for (int i = 0;i<size;i++) {
        printf("Number %d:%d\n",i+1,arr[i]);
    }

    // frequency

    for (int i = 0;i<size;i++){
        freq[i] = -1;
    }

    for (int i = 0;i<size;i++) {
        int count = 1;
        for (int j = i+1;j<size;j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0) {
            freq[i] = count;
        }

    }

    // Printing the frequency of the numbers

    printf("Elements    |   Frequency\n");
    for (int i = 0; i<size;i++) {
        if (freq[i] != 0) {
            printf("%d  |   %d\n",arr[i],freq[i]);
        }
    }


    // NOW it comes the main point -- Now we are going to count the top2 highest numbers with highest frequency
    // We could do that findind the top2 heighest integers in freq[] array and then match with the arr[] according to their order
    int max1_freq = -1, max2_freq = -1;
    int max1_num = 0, max2_num = 0;

    for (int i = 0; i < size; i++) {

        if (freq[i] <= 0)
            continue;

        // New highest frequency found
        if (freq[i] > max1_freq ||
           (freq[i] == max1_freq && arr[i] < max1_num)) {

            max2_freq = max1_freq;
            max2_num = max1_num;

            max1_freq = freq[i];
            max1_num = arr[i];
        }

        // Second highest
        else if (freq[i] > max2_freq ||
                (freq[i] == max2_freq && arr[i] < max2_num)) {

            max2_freq = freq[i];
            max2_num = arr[i];
        }
    }

    printf("\nMost frequent: %d (%d times)\n", max1_num, max1_freq);
    printf("Second most frequent: %d (%d times)\n", max2_num, max2_freq);

    return 0;
}
