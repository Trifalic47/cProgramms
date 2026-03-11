#include <stdio.h>
#include <string.h>

struct Students {
    char name[100];
    int age;
    float grade;
};

int main() {
    struct Students students[3];
    struct Students *ptr = students;

    char names[3][100] = {"hacker","Trifalic","John Hammond"};
    for (int i = 0;i<3;i++) {
        strcpy(students[i].name,names[i]);
    }
    for (int i = 0;i<3;i++) {
        // printf("Name of student %d -> %s\n",i+1,(*(ptr+i)).name);
        // WE can also do this
         printf("Name of student %d -> %s\n",i+1,(ptr+i)->name);
    }

    int ages[3] = {15,10,17};

    for (int i = 0; i< (sizeof(ages) / sizeof(ages[0]));i++) {
        students[i].age = ages[i];
    }
    for (int i = 0;i < (sizeof(ages) / sizeof(ages[0]));i++ ){
        printf("Age of the student %d -> %d\n",i+1,(ptr+i)->age);
    }

    float grades[3] = {99.8,85.56,78.45};
    for (int i = 0; i < (sizeof(grades)/sizeof(grades[0]));i++) {
         students[i].grade = grades[i];
    }

    for (int i = 0; i < (sizeof(grades)/sizeof(grades[0]));i++) {
        printf("Grades of the student %d->%.2f\n",i+1,(ptr+i)->grade);
    }

    return 0;
}
