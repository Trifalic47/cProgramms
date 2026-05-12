#include "utils.h"
#include <elf.h>

int main (int argc,char *argv[]) {
    if (argc < 2) {
        argv[1] = "test"; // 'test' is an default elf executable file which should exist for the fallback moments in the programm
    }

    /* Validating file */
    int valid_val = validate_elf(argv[1]);
    if (valid_val == -1) return 1;

    char *buff = read_header(argv[1]); // Getting the header of the file

    Elf64_Ehdr *eheader = read_elf(buff); // Elf64_Ehdr
    Elf64_Phdr *pheader = read_Phdr(buff); // Elf64_Phdr

    print_Ahdr(*eheader,*pheader);
    free(buff);

    return 0;
}
