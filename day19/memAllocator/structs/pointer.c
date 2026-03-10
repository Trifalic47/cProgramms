#include <stdio.h>

struct bio {
    int age;
    int year;
};

int main() {
    struct bio ME;
    struct bio *ptr = &ME;

    ME.age = 15;
    ME.year = 2026;

    printf("The address of the ME is -> %p\n",&ptr->age);
    printf("The pointer of the age is -> %p\n",&ptr->age);
    printf("The pointer address of the year is -> %p\n",&ptr->year);

    return 0;
}
