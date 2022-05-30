/*
** EPITECH PROJECT, 2021
** main
** File description:
** strat_ftrace
*/

#include "../include/include.h"

int ftrace(char *av, struct struc *my)
{
    if (is_system_func(av) == true) {
        Liste *liste = NULL;
        my->stat = 1;
        check_pid(liste, my);
        return (0);
    }
    open_file(av, my);
    Liste *liste = create_list();
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)my->data;
    Elf64_Shdr *shdr = (Elf64_Shdr*)((char *)my->data + ehdr->e_shoff);
    while (shdr[my->size].sh_type != SHT_SYMTAB && my->size < ehdr->e_shnum) {
        my->size++;
    }
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            liste = find_info(shdr, my, liste);
        }
    }
    check_pid(liste, my);
    return (0);
}

struct struc *init(char **av)
{
    struct struc *my;
    my = (struct struc *) malloc(sizeof(struct struc));
    my->av = av;
    my->size = 0;
    my->data = NULL;
    return (my);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "--help") == 0)
        return (help());
    else if (ac == 2) {
        struct struc *my = init(av);
        return (ftrace(av[1], my));
    }
    else {
        printf("Use --help\n");
        return 84;
    }
    return (0);
}