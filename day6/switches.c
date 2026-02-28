#include <stdio.h>

int main() {
  // Today we are going to learn about the switches in the C programming
  // language

  int day;
  printf("Enter the day:");
  scanf("%d", &day);
  printf("You entered:%d\n", day);

  switch (day) {
  case 1:
    printf("Monday\n");
    break;
  case 2:
    printf("Tuseday\n");
    break;
  case 3:
    printf("Wednesday\n");
    break;
  case 4:
    printf("Thursday\n");
    break;
  case 5:
    printf("Friday\n");
    break;
  case 6:
    printf("Saturday\n");
    break;
  case 7:
    printf("Sunday\n");
    break;
  default:
    printf("Invalid Input\n");
  }

  return 0;
}
