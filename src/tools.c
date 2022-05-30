/*
** EPITECH PROJECT, 2021
** tolls
** File description:
** ftrace_go
*/

#include "../include/include.h"

void open_file(char *filepath, struct struc *my)
{
    int fd = open(filepath, O_RDONLY, 0);
    struct stat statbuf;
    if (fd == -1)
        exit(84);
    if (fstat(fd, &statbuf) == -1) {
        close(fd);
        exit(84);
    }
    my->data = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (my->data == MAP_FAILED) {
        printf("Mapping Failed\n");
        exit(84);
    }
}

Liste *find_info(Elf64_Shdr *shdr, struct struc *my, Liste *liste)
{
    Elf64_Sym *sym = (Elf64_Sym *)((char *)my->data + shdr[my->size].sh_offset);
    Elf64_Shdr *table = &shdr[my->size];
    unsigned int partab = shdr[my->size].sh_link;
    char *tab = my->data + shdr[partab].sh_offset;
    for (int i = 0; i < table->sh_size / table->sh_entsize; i++) {
        if (sym[i].st_info != STT_FILE && sym[i].st_name != 0) {
            create(liste, sym[i].st_value, &tab[sym[i].st_name]);
        }
    }
    int count = compListoStr(liste, "main"); 
    if (count != 0)
        printf("Entering function main at 0x%08lx\n", count);
    count = compListoStr(liste, "my_putstr");
    if (count != 0)
        printf("Entering function my_putstr at 0x%08lx\n", count);
    return (liste);
}

int help(void)
{
    printf("USAGE: ftrace <command>\n");
    return (0);
}
// ret //