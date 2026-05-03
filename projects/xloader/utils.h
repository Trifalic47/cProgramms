#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char * read_header(char *file_path);
int validate_elf(char *filename);
Elf64_Ehdr * read_elf(char *buff);
