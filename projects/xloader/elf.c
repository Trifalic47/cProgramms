#include "utils.h"
#include <elf.h>

int main (int argc,char *argv[]) {
    if (argc < 2) {
        argv[1] = "test";
    }

    /* Validating file */
    int valid_val = validate_elf(argv[1]);
    if (valid_val == -1) return 1;

    char *buff = read_header(argv[1]); // Getting the header of the file

    Elf64_Ehdr *header = read_elf(buff);
    printf("OS ABI -> %u\n", header->e_ident[EI_OSABI]);

    free(buff);

    return 0;
}

