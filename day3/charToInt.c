#include <stdio.h>

int main() {
  char ch;
  printf("Enter the character:");
  scanf(" %c", &ch);
  printf("Character: %c\n", ch);

  int num = ch - '0';
  printf("Number:%d\n", num);

  return 0;
}
