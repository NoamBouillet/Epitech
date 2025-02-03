##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	setting_up.c \
			main.c \
			error_managing_and_creating_map.c \

OBJ = $(SRC:.c=.o)

SRC_TEST = tests/test_setting_up.c \

CFLAGS = -Iinclude/ -W -Wall

LDFLAGS = -L. -lmy

CRIT = -lcriterion --coverage

NAME	=	setting_up

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib_my_printf
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(MAKE) clean -C ./lib_my_printf
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
		$(MAKE) fclean -C ./lib_my_printf
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -g

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CFLAGS) $(LDFLAGS) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run coverage
