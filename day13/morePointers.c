#include <stdio.h>
#include <string.h>

char* reverseString(char *array);

int main(){
    // Today we are going to learn more about pointers
    char string[] = {"tanishq"};
    int size = sizeof(string) / sizeof(string[0]);

    reverseString(string);
    printf("Actual String: %s\n",string);

    return 0;
}

char* reverseString(char *array){
    int size = strlen(array)-1;
    int count = 0;
    for (int i = size;i > count;i--) {
        char temp = *(array + count);
        *(array + count) = *(array + i);
        *(array + i) = temp;
        count++;
    }
    return array;
}
