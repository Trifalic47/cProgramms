#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Loading...");
  fflush(stdout);
  // NOTE: Or we can use \n in the printf if we want more fast response
  sleep(3);
  return 0;
}
