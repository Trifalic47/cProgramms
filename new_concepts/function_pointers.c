#include <stdio.h>

int add (int a ,int b);

void greetMorning() { printf("Good morning\n"); }
void greetEvening() { printf("Good evening\n"); }

void greet(void (*func)()) {
    func();
}

int main() {
    int (*ptr)(int,int) = add;
    int result = ptr(2,9);
    printf("Result ->%d\n",result);

    greet(greetMorning);
    greet(greetEvening);

    return 0;
}

int add (int a ,int b) {
    return a+b;
}
