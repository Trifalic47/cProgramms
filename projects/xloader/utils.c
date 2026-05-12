#include "utils.h"

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
    // for (int i = 0; i < 4; i++) {
    // printf("0x%02x ", buf[i]);
    // }

    fclose(elf_fd);
    return 0;
}

Elf64_Ehdr * read_elf(char *buff) {
    Elf64_Ehdr *header = (Elf64_Ehdr*)buff;
    return header;
}

Elf64_Phdr * read_Phdr(char *buff) {
    Elf64_Phdr *header = (Elf64_Phdr*)buff;
    return header;
}

void print_Ahdr(Elf64_Ehdr eheader, Elf64_Phdr pheader) {

    /* Printing the ELF Header -> Elf64_Ehdr */
    printf("------------------ ELF Headers ------------------\n");

    printf("Magic Bytes      : ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", eheader.e_ident[i]);
    }
    printf("\n");

    printf("Class            : %u\n", eheader.e_ident[EI_CLASS]);
    printf("Data Encoding    : %u\n", eheader.e_ident[EI_DATA]);
    printf("ELF Version      : %u\n", eheader.e_ident[EI_VERSION]);
    printf("OS ABI           : %u\n", eheader.e_ident[EI_OSABI]);
    printf("ABI Version      : %u\n", eheader.e_ident[EI_ABIVERSION]);

    printf("Type             : %u\n", eheader.e_type);
    printf("Machine          : %u\n", eheader.e_machine);
    printf("Version          : %u\n", eheader.e_version);

    printf("Entry Point      : 0x%lx\n", eheader.e_entry);

    printf("Program Hdr Off  : %lu\n", eheader.e_phoff);
    printf("Section Hdr Off  : %lu\n", eheader.e_shoff);

    printf("Flags            : %u\n", eheader.e_flags);

    printf("ELF Header Size  : %u\n", eheader.e_ehsize);

    printf("Program Hdr Size : %u\n", eheader.e_phentsize);
    printf("Program Hdr Num  : %u\n", eheader.e_phnum);

    printf("Section Hdr Size : %u\n", eheader.e_shentsize);
    printf("Section Hdr Num  : %u\n", eheader.e_shnum);

    printf("String Tbl Index : %u\n", eheader.e_shstrndx);

    /* Printing Program Header -> Elf64_Phdr */
    printf("\n---------------- Program Header ----------------\n");

    printf("Type             : %u\n", pheader.p_type);
    printf("Flags            : %u\n", pheader.p_flags);

    printf("Offset           : 0x%lx\n", pheader.p_offset);
    printf("Virtual Address  : 0x%lx\n", pheader.p_vaddr);
    printf("Physical Address : 0x%lx\n", pheader.p_paddr);

    printf("File Size        : %lu\n", pheader.p_filesz);
    printf("Memory Size      : %lu\n", pheader.p_memsz);

    printf("Alignment        : %lu\n", pheader.p_align);
    printf("\n----------------- Program Execution -------------------------------\n");
}
