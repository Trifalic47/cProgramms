#include <stdio.h>

void printd(int n){
    if (n < 0) {
    putchar('-');
    n = -n;
    }
    if (n / 10){
    printd(n / 10);
    }
    putchar(n % 10 + '0');
}

int main() {
    /*
        Recursion ->
        C functions may be used recursively; that is, a function may call itself either directly or
        indirectly. Consider printing a number as a character string. As we mentioned before, the digits
        are generated in the wrong order: low-order digits are available before high-order digits, but
        they have to be printed the other way around
        (page 73)
    */
    printd(3);
    printf("\n");
    return 0;
}
