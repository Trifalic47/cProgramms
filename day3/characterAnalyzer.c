#include <ctype.h>
#include <stdio.h>

int main() {
  char character;
  printf("Enter the charcter:");
  scanf(" %c", &character);

  // Analyzing the type of the character
  if (isalpha(character)) {
    printf("Type: Alphabet\n");
    printf("ASCII Value: %d\n", character);
  } else if (isdigit(character)) {
    printf("Type: Digit\n");
    int integerValue = character - '0';
    printf("Integer Value: %d\n", integerValue);
  } else {
    printf("Type: Special Character\n");
    printf("ASCII Value: %d\n", character);
  }

  return 0;
}
