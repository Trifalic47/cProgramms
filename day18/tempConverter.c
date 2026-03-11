#include <stdio.h>

float convert(int cel);
void intInput(int *num, char *text);

int main() {
    int cel;
    char text[] = {"Enter the celcious value to convert:"};
    intInput(&cel,text);
    float far = convert(cel);
    printf("Celcius -> %d\tFarnehit -> %.2f\n",cel,far);
}

float convert(int cel) {
    float res = ((float)cel * 9/5) + 32;
    return res;
}

void intInput(int *num,char *text) {
    printf("%s",text);
    scanf("%d",num);
}
