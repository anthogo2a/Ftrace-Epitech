##
## EPITECH PROJECT, 2021
## makefile_strace
## File description:
## strace_tech2
##

NAME	=	ftrace

ASM		=	nasm

CC		=	gcc

SRC		=	src/main.c  			\
			src/info.c				\
			src/tools.c				\
			src/linked_list.c		\
			src/syscall.c			\

OBJ		=	${SRC:.c=.o}

CFLAGS	=	-I include/ -g3 -Wall

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -l elf

all:    $(NAME)

clean:
	rm -fr $(OBJ)

fclean:	clean
	rm -fr $(NAME)

re:	fclean all




