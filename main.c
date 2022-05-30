#include <unistd.h>
#include <stdio.h>

void my_putstr(char *str)
{
    write(1, "toto\n", 5);
}

int main()
{
    my_putstr("to");
}