#include <stdio.h>

typedef struct employee {
    char *name;
} emp;

int main() {
    emp e;
    e.name = "r00tgr3p";
    printf("The name of the hacker is -> %s\n",e.name);
    return 0;
}

/*
    Explanation -> The use of typedef is to add alias to another datatype for the reliability in the code like ->
    typedef int num;

    now we can also declare the number as -> num a = 20; // now this num is an alias of int data type
* */
