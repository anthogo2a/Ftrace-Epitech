/*
** EPITECH PROJECT, 2021
** infooo
** File description:
** trace_list_touca
*/

#include "../include/include.h"

void check_pid(Liste *liste, struct struc *my)
{
    my->pid = fork();
    switch (my->pid) {
        case -1:
            printf("Error pid\n");
            exit (84);
        case 0:
            ptrace(PTRACE_TRACEME, 0, NULL, NULL);
            if (my->stat == 1)
                execvp(my->av[1], &my->av[1]);
            else
                execv(my->av[1], &my->av[1]);
        default :
            strace(my, liste);
            exit(0);
    }
}

int strace(struct struc *my, Liste *liste)
{
    struct user_regs_struct regs;
    int statue = 0;
    wait(&statue);
    while (!WIFEXITED(statue)) {
        if (ptrace(PTRACE_GETREGS, my->pid, NULL, &regs) == -1) exit(84);
        if ((int) regs.orig_rax != -1)
            if (check(&regs)) {
                display(&regs, my);
            }
        ptrace(PTRACE_SINGLESTEP, my->pid, NULL, NULL);
        wait(&statue);
    }
    printf("Leaving function main\n");
    printf("+++ exited with 0x%x +++\n", regs.rdi);
    return (0);
}

bool is_system_func(char *func)
{
    char str[100] = "/bin/";
    strcat(str, func);
    if (access(str, F_OK ) == 0) {
        return (true);
    }
    else
        return (false);
}