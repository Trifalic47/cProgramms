#include <stdio.h>

void stringInput(char *filename,char *string);

int main() {
    char filename[100];
    char text[100] = {"Enter the name of the file to open:"};
    char string[100];
    stringInput(filename,text);

    FILE *read = NULL;
    read = fopen(filename,"r");
    if (read == NULL) {
        printf("Failed to open the file.. \n Quitting the program... \n");
        return 1;
    }

    while (fgets(string,sizeof(string),read) != NULL) {
        printf("%s",string);
    }

    return 0;
}

void stringInput(char *filename,char *string) {
    printf("%s",string);
    scanf("%s",filename);
}
