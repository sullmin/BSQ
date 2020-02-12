##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/part_double_tap.c	\
		src/first_line.c	\
		src/my_algo.c	\
		src/myread.c	\
		src/algo_part_two.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	+=	-Wall	-Wextra	-I./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o	$(NAME)	$(OBJ) -L./lib/my -lmy

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all
