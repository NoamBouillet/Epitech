##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	majorit_files/my_ls.c \
			include/structs.h \
			majorit_files/flags_detection.c \
			include/ls_functions.h \
			main.c \
			majorit_files/create_list_files_dirs.c \
			once_used_functions/my_memcpy.c \
			majorit_files/initialize_nodes.c \
			majorit_files/apply_flags.c \
			majorit_files/flags_functions.c \
			once_used_functions/my_revlist.c \
			once_used_functions/delete_nodes.c \
			once_used_functions/list_size.c \
			dash_l/permissions.c \
			dash_l/dash_l.c \
			once_used_functions/copying_path.c \
			once_used_functions/time_sort.c \
			once_used_functions/sort_alphabetical.c \

OBJ = $(SRC:.c=.o)

SRC_TEST = tests/test_my_ls.c \

CFLAGS = -Iinclude/. -W -Wall

LDFLAGS = -L. -lmy

CRIT = -lcriterion --coverage

NAME	=	my_ls

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libprintf
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(MAKE) clean -C ./libprintf
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
		$(MAKE) fclean -C ./libprintf
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -g

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CFLAGS) $(LDFLAGS) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/
