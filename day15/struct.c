#include <stdio.h>

struct addition {
    int x;
    int y;
    int result;
};

int main() {
    struct addition math;
    math.x = 20;
    math.y = 100;
    math.result = math.x + math.y;

    printf("The sum of %d and %d is -> %d\n",math.x,math.y,math.result);

    return 0;
}
