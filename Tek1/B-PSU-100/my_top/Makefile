##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	include/structs.h \
			include/top_functions.h \
			main.c \
			lib/my_str_to_word_array.c \
			processes/data_proc.c \
			processes/complex_data_proc.c \
			main_architecture/printing_window.c \
			main_architecture/flags_detection.c \
			main_architecture/create_list_processes.c \
			header/first_line.c \
			header/task_line.c \
			header/cpu_line.c \
			header/mem_line.c \
			header/mem_swap_line.c \
			processes/get_shared_and_cpu.c \

OBJ = $(SRC:.c=.o)

SRC_TEST = tests/test_my_top.c \

CFLAGS = -Iinclude/. -W -Wall -lncurses

DFLAGS = -Iinclude/. -W -Wall -lncurses -g

CRIT = -lcriterion --coverage

NAME	=	my_top

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete
	find . -type f -name '*.o' -delete

fclean: clean
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(OBJ) $(DFLAGS)

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CFLAGS) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/
