/*
** EPITECH PROJECT, 2021
** sycall
** File description:
** print_file
*/

#include "../include/include.h"
#include "../include/syscall.h"

int check(struct user_regs_struct *regs)
{
    if (regs->orig_rax > 328) {
        printf("Unknow\n");
        return (0);
    }
    switch (regs->orig_rax) {
        case (231):
	        printf("+++ exited with %lld +++\n", regs->rdi);
            return (1);
        default:
            return (1);
    }
}

void choose(int i, unsigned long long reg, char sys)
{
    if (sys == INT) {
       printf("%1d", reg);
    }
    else
        printf("%#lx", my_syscall[i]);
}

void print(struct user_regs_struct *regs, struct struc *my)
{
    int i = 0;
    int len = my_syscall[regs->orig_rax].nb;
    printf("Syscall %s(", my_syscall[regs->orig_rax].str);
    while (i < len) {
        if (i == 0)
            choose(i, regs->rdi, my_syscall[regs->orig_rax].ag1);
        else if (i == 1)
            choose(i, regs->rsi, my_syscall[regs->orig_rax].ag2);
        else if (i == 2)
            choose(i, regs->rdx, my_syscall[regs->orig_rax].ag3);
        else if (i == 3)
            choose(i, regs->rcx, my_syscall[regs->orig_rax].ag4);
        else if (i == 4)
            choose(i, regs->r8, my_syscall[regs->orig_rax].ag5);
        else if (i == 5)
            choose(i, regs->r9, my_syscall[regs->orig_rax].ag6);
        if (i != len - 1)
            printf(", ");
        i++;
    }
    printf(") = %#llx\n", regs->rax);
}

void display(struct user_regs_struct *regs, struct struc *my)
{
    my->tab[0] = regs->rdi;
    my->tab[1] = regs->rsi;
    my->tab[2] = regs->rdx;
    my->tab[3] = regs->rcx;
    my->tab[4] = regs->r8;
    my->tab[5] = regs->r9;
    print(regs, my);
}