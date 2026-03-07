#include <stdio.h>
#include <stdlib.h>

/*
    Task — Dynamic Student Records

    Ask the user how many students they want to enter
    Allocate an array of that size on the heap
    Each student has a name (char array) and a marks (int) — use a struct
    Take input for each student
    Print all students
    Free everything
    */
typedef struct Student {
    char name[50];
    int marks;
} Student;

void input(int *size,char text[]);
void studentsInput(Student *arr,int size);
void printStudents(Student *arr,int size);
void printTopper(Student *arr,int size);

int main() {
    int size;
    char text[] = "How many students you want to enter:";
    input(&size,text);

    Student *students = malloc(size * sizeof(Student));
    studentsInput(students,size);
    printStudents(students, size);
    printTopper(students,size);
    free(students);
    return 0;
}


void input(int *size,char text[]) {
    printf("%s",text);
    scanf("%d",size);
}


void studentsInput(Student *arr,int size) {
    for (int i = 0;i< size ;i++) {
        printf("Enter the name of the student %d:",i+1);
        scanf("%s",arr[i].name);
        printf("Enter the marks of the student %d:",i+1);
        scanf("%d",&arr[i].marks);
    }
}


void printStudents(Student *arr,int size) {
    for (int i = 0; i< size;i++) {
        printf("%d.Name-> %s\tMarks->%d\n",i+1,arr[i].name,arr[i].marks);
    }
}


void printTopper(Student *arr,int size) {
    int highest = arr[0].marks;
    int index = -1;
   for (int i = 0 ;i < size ;i++){
        if (arr[i].marks > highest) {
            highest = arr[i].marks;
            index = i;
        }
    }
    printf("The highest marks in the class are -> %d\n",highest);
    printf("The topper of the class is -> %s\n",arr[index].name);
}
