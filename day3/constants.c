#include <stdio.h>

int main() {
  // Constants are those whose values cant be changed if they are once declared.
  // For example you can see here->
  const float pi = 3.14;
  // Now we can't change the value of pi because its declared using 'const'
  // keyword pi = 21/7  -> Now this line of code will give us an error because
  // the value of pi now can't be changed.
  printf("The value of float is %.2f\n", pi);
  return 0;
}
