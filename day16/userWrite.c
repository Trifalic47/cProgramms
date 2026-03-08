#include <stdio.h>

void stringInput(char *filename,char *string);

int main() {
    char filename[100];
    char text[] = {"Enter the filename to write data into:"};;

    stringInput(filename,text);
    while (getchar() != '\n');

    FILE *write = NULL;
    write = fopen(filename,"w");

    char data[1000];
    printf("Enter the text you want to enter:");
    fgets(data,sizeof(data),stdin);
    printf("%s",data);

    fprintf(write,"%s",data);

    return 0;
}

void stringInput(char *filename,char *string) {
    printf("%s",string);
    scanf("%s",filename);
}
