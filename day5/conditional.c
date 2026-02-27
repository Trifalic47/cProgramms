#include <stdio.h>

int main() {
  int age;
  printf("Enter your age:");
  scanf("%d", &age);
  printf("You are %d years old\n", age);
  if (age >= 18) {
    printf("You are an adult\n");
  } else if (age <= 17 && age >= 13) {
    printf("Your are an teenager\n");
  } else if (age <= 12 && age >= 1) {
    printf("You are an kid\n");
  } else if (age == 0 || age < 0) {
    printf("Have you born yet??\n");
  } else {
    printf("Add valid age\n");
  }

  return 0;
}
