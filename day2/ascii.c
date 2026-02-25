#include <ctype.h>
#include <stdio.h>

int main() {
  for (char c = 'a'; c <= 'z'; c++) {
    printf("%c -> %d\t", c, c);
    printf("%c -> %d\n", toupper(c), toupper(c));
  }
  return 0;
}
