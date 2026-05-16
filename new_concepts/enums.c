#include <stdio.h>

enum Machine {
    Windows,
    Linux,
    Mac,
};

int main() {
    enum Machine trifalic_machine = Linux;

    /* Using if-else statements ->
     if (trifalic_machine == Linux) {
         printf("You are an linux user\n");
     } else if (trifalic_machine == Windows) {
         printf("You are an windows user\n");
     } else if (trifalic_machine == Mac) {
         printf("You are an mac user\n");
     } else {
         printf("Do you use something??\n");
     }

     */

    /*  Or we could use the switch statements */
    switch (trifalic_machine) {
        case Linux:
            printf("You are an Linux user\n");
            break;
        case Windows:
            printf("You are an windows user\n");
            break;
        case Mac:
            printf("You are an mac user\n");
            break;
        default:
            printf("Do you use something??\n");
    }

    return 0;
}
