#include <ctype.h>
#include <stdio.h>

int main() {
  char character;
  printf("Enter any character:");
  scanf(" %c", &character);

  // Using isidigit() function from ctype.h to check if the char is an digit or
  // not and we wil also check of alphabet

  printf("Your input:%c\n", character);
  if (isdigit(character)) {
    printf("You entered an digit\n");
  } else if (isalpha(character)) {
    printf("You entered an alphabet\n");
  } else if (!isalnum(character)) {
    printf("You entered an special character\n");
  } else {
    printf("Sus input..\n");
  }

  return 0;
}
