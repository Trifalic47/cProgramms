#include <stdio.h>

int main() {
  /*
   * The use of an scanf ->
   * We use scanf to take some data as an input from an user.We can take the
   * input values in the form of an integer,character,float and more.
   */

  // Taking integer as an input

  int age;
  printf("Enter your age:");
  scanf("%d", &age);
  printf("Your age is %d\n", age);

  // Taking character as an input
  char firstLetterOfName;
  printf("Enter the first letter of your name:");
  scanf(" %c", &firstLetterOfName);
  printf("The first letter of your name is: %c\n", firstLetterOfName);

  // Taking float as an input
  float percentage;
  printf("Enter the percentage of marks you got maximum in your school:");
  scanf("%f", &percentage);
  printf("You got: %.2f%% as maximum percentage in school\n", percentage);

  return 0;
}
