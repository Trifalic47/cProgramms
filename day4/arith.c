#include <stdio.h>

int main() {
  // Arithmetic operators are those operators which are used to perform
  // methametical operations in C like +,-,/,*,%

  // Using these on variables x and y

  int x, y;
  x = 10;
  y = 2;

  int sum = x + y;
  int sub = x - y;
  int mul = x * y;
  float divide = x / y;
  int mod = x % y;

  printf("Addition: %d\n", sum);
  printf("Subsraction: %d\n", sub);
  printf("Multiply: %d\n", mul);
  printf("Divide: %.2f\n", divide);
  printf("Mod: %d\n", mod);

  // Using parentheses in the arithmetic calculations

  float all = (sum - sub) * (mul / divide) + (mod);

  printf("The arithmetic operation using parentheses is:%.2f\n", all);

  return 0;
}
