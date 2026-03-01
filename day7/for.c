#include <math.h>
#include <stdio.h>

int main() {
  // NOTE: We have to run the command with -lm command -> gcc for.c -o for -lm
  int num;
  printf("Till how much numbers you want to print squares of numbers:");
  scanf("%d", &num);

  for (int i = 1; i <= num; i++) {
    int square = pow(i, 2);
    printf("Square of %d: %d\n", i, square);
  }

  return 0;
}
