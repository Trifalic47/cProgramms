#include <stdio.h>

int main() {

    FILE *read = NULL;
    char string[100];
    read = fopen("test.txt","r");
    if (read == NULL) {
        printf("Failed to open the file\n");
        return 1;
    }
    // This while loop will read the strings from the test.txt until it reach at the end of the file (EOF)
    while (!feof(read)) {
        fscanf(read,"%s",string);
        printf("%s ",string);
    }
    printf("\n");

    fclose(read); // Close the file pointer

    return 0;
}
