#include <stdio.h>

void birthday(int iter,char *name);

int main(){
    // Using birthday function
    char name[50];
    printf("Enter your name:");
    fgets(name,sizeof(name),stdin);

    int num;
    printf("How many times do you want to print happy birthday:");
    scanf("%d",&num);

    birthday(num,name);

    return 0;
}


void birthday(int iter,char *name){
    for (int i = 1; i <= iter;i++){
        printf("%d. Happy birthday %s",i,name);
    }
}
