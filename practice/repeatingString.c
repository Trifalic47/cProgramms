#include <stdio.h>
#include <string.h>

int main(){
    // Find the character in the string which is the non repeating

    char string[100];
    printf("Enter the string:");
    fgets(string,100,stdin);
    string[strcspn(string, "\n")] = '\0';
    printf("String -> %s\n",string);

    int size = strlen(string);

    int freq[size];

    for (int i = 0 ; i < size;i++) {
        freq[i] = -1;
    }

    for (int i = 0;i < size ; i++) {
        int count = 1;
        for (int j=i+1;j<size;j++){
            if (string[i] == string[j]) {
                count ++;
                freq[j] = 0;
            }
        }
         if (freq[i] != 0) {
                freq[i] = count;
        }
    }


    printf("These characters only came one time\n");
    for (int i = 0; i < size; i++) {
        if (freq[i] == 1) {
            printf("%c -> %d\n",string[i],freq[i]);
        }
    }

    return 0;
}


