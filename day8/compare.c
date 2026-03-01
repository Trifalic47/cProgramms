#include <stdio.h>

int compare(int a,int b);

int main(){
    // Using this compare function
    int a,b;
    printf("Enter the value of a:");
    scanf("%d",&a);

    printf("Enter the value of b:");
    scanf("%d",&b);

    int bigger = compare(a,b);
    if (bigger == a && bigger == b) {
        printf("Both the numbers are equal\n");
    }
    else {
    printf("The bigger number is: %d\n",bigger);
    }

    return 0;
}


int compare(int a,int b){
    if (a > b) {
        return a;
    }else if(a < b){
        return b;
    } else if(a == b){
        return a;
    }else{
        return 0;
    }
}
