#include <stdio.h>

void stringInput(char *filename,char *string);

int main() {
    char filename[100];
    char text[] = {"Enter the fileName in which you want to append the data:"};

    stringInput(filename,text);

    FILE *append = NULL;
    append = fopen(filename,"a");

    char data[1000];
    printf("Enter the data you want to enter in the file:");
    fgets(data,sizeof(data),stdin);

    fprintf(append,"%s",data);

    return 0;
}

void stringInput(char *filename,char *string) {
    printf("%s",string);
    scanf("%s",filename);
    while (getchar() != '\n');
}
