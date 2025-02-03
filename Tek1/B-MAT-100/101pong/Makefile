##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for pong
##

SRC = 	pong.c \
		absolute_value.c \

NAME = 101pong

LCFLAGS = --coverage -lcriterion

all:
	gcc -o $(NAME) $(SRC) -lm

clean:
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(LCNAME)
	rm -f $(NAME)

re:		fclean all
