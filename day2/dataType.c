#include <stdio.h>

int main() {
  // Integer data type and its printing method
  int age = 14;
  printf("My age is %d\n", age);

  // Floating data type and its printing method
  float pi = 3.14;
  printf("The value of pi is %.2f\n", pi);

  // Characters and its printing method
  char nameStartingLetter = 'T';
  printf("The starting letter of my name is \'%c\'\n", nameStartingLetter);
  printf("The ASCII value of the %c is %d\n", nameStartingLetter,
         nameStartingLetter);
  return 0;
}
