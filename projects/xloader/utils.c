#include "utils.h"
#include <elf.h>

char *read_header(char *file_path) {
    FILE *fd = fopen(file_path, "rb");
    char *buff = (char*)malloc(64);
    fread(buff, sizeof(char), 64, fd);
    fclose(fd);
    return buff;
}

int validate_elf(char *filename) {
    unsigned char buf[16];
    FILE *elf_fd = fopen(filename, "rb");
    if (elf_fd == NULL) {
    printf("Failed to open the file\n");
    return -1;
    }
    size_t size_read = fread(buf, sizeof(char), 16, elf_fd);
    if (size_read <= 0) {
    printf("Failed to read file.\n");
    return -1;
    }

    /* Checking if the file is elf binary or not */
    char expected_hex[4] = {0x7f, 0x45, 0x4c, 0x46};

    for (int i = 0; i < 4; i++) {
    if (buf[i] == expected_hex[i]) {
      continue;
    } else {
      printf("Not an elf file\n");
      return -1;
    }
    }

    /* Printing 1st 4 hex ..*/
    for (int i = 0; i < 4; i++) {
    printf("0x%02x ", buf[i]);
    }

    fclose(elf_fd);
    return 0;
}

Elf64_Ehdr * read_elf(char *buff) {
    Elf64_Ehdr *header = (Elf64_Ehdr*)buff;
    return header;
}
