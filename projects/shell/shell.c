#include "utils.h"

int main() {
    while (1) {
        char cmd[100];
        print("Trishell:");
        stringInput(cmd);
        if (stringCompare(cmd,"exit") == 0) {
            print("Exiting from terminal..\n");
            return 0;
        }
    }

    return 0;
}


