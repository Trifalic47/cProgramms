#include <stdio.h>

int main(){

    // One dimensional arrays in C

    // Making an array to store the ages of user-> (Note: We will use the loops to take the input and print the output so it will use
    // some previous concepts)

//    int ages[5]; // Total users = 5
    int ages[5] = {12,6,45,67,45};
    int totalUsers = sizeof(ages) / sizeof(ages[0]);

    int minors[5];
    int minorsIndex = 0;
    for (int i = 0;i < totalUsers;i++) {
        int age = ages[i];
        printf("The age of user %d is %d\n",i+1,age);
        if(age <= 17) {
            minors[minorsIndex] = age;
            minorsIndex++;
        }
    }

    int totalMinors = sizeof(minors) / sizeof(minors[0]);
    for (int i = 0;i<totalMinors;i++) { // Here we can use the minorsIndex to compare with i but we also want to use the continue statement for understanding
        if (minors[i] == 0) {
            continue;
        }
        printf("%d\n",minors[i]);
    }

    return 0;
}
