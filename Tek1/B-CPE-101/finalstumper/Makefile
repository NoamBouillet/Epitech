##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	./rush3.c \
			main.c \
			rush_function1.c \
			rush_function2.c \
			rush_function3.c \
			rush_function4.c \
			rush_function5.c \
			my_put_nbr.c \
			my_putstr.c \
			my_putchar.c \
			my_strcat.c \
			my_strlen.c \
			my_strcmp.c \
			functions_exceptions.c \

SRC_TEST = ../tests/test_rush3.c \
		$(SRC)

OBJ		=	$(SRC:.c=.o)

CFLAGS = -I/. -W -Wall

NAME	=	rush3

TEST_NAME = unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o rush3 $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f **/*.gcda
		rm -f **/*.gcno

fclean: clean
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(SRC) $(CFLAGS)-g

tests_run:
	gcc -o $(TEST_NAME) $(SRC_TEST) $(CFLAGS) -lcriterion

coverage:
	gcc -o $(TEST_NAME) $(SRC_TEST) $(CFLAGS) -lcriterion --coverage
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests coverage
