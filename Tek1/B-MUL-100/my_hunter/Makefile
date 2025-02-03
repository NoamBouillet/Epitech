##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	hunter_functions/my_hunter.c \
			hunter_functions/loading.c \
			hunter_functions/sprites_updates.c \
			hunter_functions/sprites_creation.c \
			hunter_functions/crosshair_and_shoot.c \
			hunter_functions/score_and_lives.c \
			lib_functions/my_strcmp.c \
			lib_functions/int_to_string.c \
			lib_functions/my_strcat.c \
			lib_functions/my_strcpy.c \
			main.c \
			menu.c \
			restart.c \

OBJ = $(SRC:.c=.o)

SRC_TEST = tests/test_my_hunter.c \

CRIT = -lcriterion --coverage

FLAGS = -W -Wall -lcsfml-graphics -lcsfml-system \
	-lcsfml-audio -I. -lcsfml-window

NAME	=	my_hunter

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(OBJ) $(FLAGS) -g

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run coverage
