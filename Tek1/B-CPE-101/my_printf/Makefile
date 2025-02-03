##
## EPITECH PROJECT, 2024
## lib Makefile
## File description:
## make
##

SRC		=	lib/my/my_printf.c \
			lib/my/lib/my_getnbr.c \
			lib/my/lib/my_putchar.c \
			lib/my/lib/my_strlowcase.c \
			lib/my/display_flag/my_put_exp.c \
			lib/my/display_flag/my_put_percent.c \
			lib/my/display_flag/my_put_hexa.c \
			lib/my/display_flag/my_put_octal.c \
			lib/my/display_flag/my_putchar_buffer.c \
			lib/my/display_flag/my_put_nbr.c \
			lib/my/display_flag/my_putstr.c \
			lib/my/display_flag/my_put_longint.c \
			lib/my/display_flag/my_putfloat.c \
			lib/my/display_flag/my_put_pointer.c \
			lib/my/display_flag/my_put_length.c \
			lib/my/lib/my_revstr.c \
			lib/my/lib/my_len_nbr.c \
			lib/my/lib/my_strlen.c \
			lib/my/error_handling.c \
			lib/my/format_modifiers/my_flag.c \
			lib/my/format_modifiers/my_speci.c \
			lib/my/format_modifiers/my_width.c \
			lib/my/format_modifiers/my_precision.c \
			lib/my/format_modifiers/my_length.c \
			lib/my/my_flag_gestion.c \
			lib/my/format_modifiers/show_modifiers.c \
			lib/my/display_flag/my_put_binary.c \

SRC_TEST = tests/test_my_printf.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS = -Iinclude/ -W -Wall

LDFLAGS = -L. -lmy

CRIT = -lcriterion --coverage

NAME	=	libmy.a

TEST_NAME = unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
		rm -f $(NAME)

re:     fclean all

debug:
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS) -g

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CFLAGS) $(LDFLAGS) $(CRIT)
	./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run
