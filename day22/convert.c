#include <stdio.h>

void binary(int decimal);
void intInput(int *num,char *text);
void hex(int decimal);
void size();

int main() {
    int decimal;
    char text[] = "Enter the number to convert:";
    intInput(&decimal,text);
    binary(decimal);
    hex(decimal);
    size();
    return 0;
}

void binary(int decimal) {
    for (int bit = 31;bit >=0;bit--) {
        printf("%d",(decimal>>bit)&1);
    }
    printf("\n");
}

void intInput(int *num,char *text) {
    printf("%s",text);
    scanf("%d",num);
}

void hex(int decimal) {
    int remainders[16];
    int remainder;
    char digits[] = "0123456789ABCDEF";
    int i=0;
    while (decimal != 0) {
        remainder = decimal %16;
        remainders[i] = remainder;
        i++;
        decimal = decimal / 16;
    }
    printf("Positions\n");
    int j = i-1;
    while(j >= 0){
        printf("%d\t",remainders[j]);
        j--;
    }
    printf("\n");

    printf("Hex Values\n");
    int k = i-1;
    printf("0x");
    while (k>=0) {
        printf("%c",digits[remainders[k]]);
        k--;
    }
    printf("\n");
}

void size() {
    printf("\n");
    printf("int: %zu bytes\n", sizeof(int));
    printf("char: %zu bytes\n", sizeof(char));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
}
