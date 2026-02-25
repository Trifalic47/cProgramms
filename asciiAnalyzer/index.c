#include <ctype.h>
#include <stdio.h>

int main() {

  /* Expected Output
  Character: A
  ASCII: 65
  Type: Alphabet
  Lowercase: a
   * */
  char ch;
  printf("Enter the character:");
  scanf("%c", &ch);

  printf("Character: %c\n", ch);
  printf("ASCII: %d\n", ch);
  if (isalpha(ch)) {
    printf("Type: Alphabet\n");
    if (isupper(ch)) {
      printf("Type: Uppercase\n");
    } else if (islower(ch)) {
      printf("Type: Lowercase\n");
    }
  } else if (isdigit(ch)) {
    printf("Type: Digit\n");
  } else {
    printf("Type: SpecialCharacter\n");
  }

  return 0;
}
