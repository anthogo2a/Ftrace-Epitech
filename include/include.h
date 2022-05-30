/*
** EPITECH PROJECT, 2021
** include
** File description:
** fttrace
*/

#ifndef oko
#define oko

#include <elf.h>
#include <gelf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libelf.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <stdbool.h>

enum type {
    CHAR_STR,
    ARG,
    NOTHING,
    INT
};

typedef struct Sys Sys;
struct Sys
{
    long unsigned int adr;
    char *name;
    Sys *next;
};

typedef struct Liste Liste;
struct Liste
{
    Sys *premier;
};

typedef struct struc
{
    void *data;
    pid_t pid;
    int size;
    size_t tab[6];
    char **av;
    int stat;
} my;

int help(void);
int main(int ac, char **av);
struct struc *init(char **av);
bool is_system_func(char *func);
int ftrace(char *av, struct struc *my);
int check(struct user_regs_struct *regs);
int strace(struct struc *my, Liste *liste);
void check_pid(Liste *liste, struct struc *my);
void open_file(char *filepath, struct struc *my);
void args(struct user_regs_struct *regs, struct struc *my);
void display(struct user_regs_struct *regs, struct struc *my);
Liste *find_info(Elf64_Shdr *shdr, struct struc *my, Liste *liste);

// Linked list //
Liste *create_list();
void DispListe(Liste *liste);
void DispListeAt(Liste *liste, int pos);
long unsigned int compListoStr(Liste *liste, const char *str);
void create(Liste *liste, int addresse, char *name);

#endif /* !oko */
