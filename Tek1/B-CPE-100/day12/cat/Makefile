##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	cat.c \
            main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS = -I../include/ -L../lib/my/ -lmy -W -Wall

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		make clean -C ../lib/my
		rm -f $(OBJ)

fclean: clean
		make fclean -C ../lib/my
		rm -f $(NAME)

re:     fclean all
		make re -C ../lib/my
