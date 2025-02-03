##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	main.c \
			shell_functions/delete.c \
			shell_functions/add.c \
			shell_functions/disp.c \
			shell_functions/sort.c \
			my_revlist.c \
			shell_functions/compare_functions.c \

OBJ = $(SRC:.c=.o)

SRC_TEST = tests/tests_organized.c \

CFLAGS = -I./include/ -W -Wall

DFLAGS = -I./include/ -W -Wall -g

LDFLAGS = -L. -lmy -lshell

CRIT = -lcriterion --coverage

NAME	=	organized

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libprintf
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(MAKE) clean -C ./libprintf
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete
	find . -type f -name '*.o' -delete

fclean: clean
		$(MAKE) fclean -C ./libprintf
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(OBJ) $(DFLAGS) $(LDFLAGS)

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CFLAGS) $(LDFLAGS) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run coverage
