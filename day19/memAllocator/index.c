#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Writing own malloc in C. Check my github -> https://github.com/Trifalic47 and my C programms on-> https://github.com/Trifalic47/cProgramms

int main() {
    char* message = "This is an message from the heap";
    size_t message_size = (strlen(message)+1) * sizeof(char);
    char *memory = sbrk(message_size);

    strcpy(memory,message);
    brk(memory);

    return 0;
}
