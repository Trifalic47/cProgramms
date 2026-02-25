#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Loading...");
  fflush(stdout);
  sleep(3);
  return 0;
}
