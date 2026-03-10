#include <stdio.h>
#include <string.h>

struct Students {
    char name[100];
    int age;
    float grade;
};

int main() {
    struct Students hacker;
    struct Students *hackerPointer = &hacker;

    strcpy(hacker.name,"hacker");
    hacker.age = 15;
    hacker.grade = 99.99;

    printf("The memory address of hacker is ->%p\n",hackerPointer);
    printf("The memory address of the hacker.name is -> %p\n",&hackerPointer->name);
    printf("The memory addrress of the hacker.age is -> %p\n",&hackerPointer->age);
    printf("The memory address of the hacker.grade is -> %p\n",&hackerPointer->grade);

    return 0;
}
