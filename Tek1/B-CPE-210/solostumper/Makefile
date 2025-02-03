##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Runs the program
##

SRC		= 	main.c \
			my_str_to_word_array.c \
			my_strcmp.c \
			my_strdup.c \
			my_strlen.c \

OBJ = $(SRC:.c=.o)

CRIT = -lcriterion --coverage

FLAGS = -W -Wall -Wextra -I.

DFLAGS = $(FLAGS) -g

NAME	=	countwords

GREEN   = \e[1;32m
BLUE    = \e[1;34m
YELLOW  = \e[1;33m
RED     = \e[1;31m
RESET   = \e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(GREEN)[+++] Compilation done. \n./$(NAME) my G. Have fun.$(RESET)"

%.o: %.c
	@echo "$(BLUE)[Compiling $< to $@]$(RESET)"
	@cc -c $< -o $@ $(FLAGS)

clean:
	@echo "$(RED)[-] Removing object files...$(RESET)"
	@rm -f $(NAME)
	@find . -name "*.gcda" -delete
	@find . -name "*.gcno" -delete
	@find . -type f -name "*.o" -delete
	@echo "$(RED)[-] Cleaning done.$(RESET)"

fclean:	clean
	@echo "$(YELLOW)[-] Removing $(NAME) binary...$(RESET)"
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f /*~
	@rm -f *#
	@rm -f *.g*
	@rm -f *.o
	@echo "$(YELLOW)[-] Fcleaning done.$(RESET)"

re:     fclean all

debug: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(DFLAGS)
	@echo "$(GREEN)[+++] Compilation done with debugging. \n\
	valgrind ./$(NAME). Have no fun.$(RESET)"

tests_run: $(NAME)
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(CRIT)
	./$(TEST_NAME)

coverage: gcovr --exclude tests/

among_us:
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀$(RESET)"
	@echo "$(RED)⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀$(RESET)"
	@echo "$(RED)⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀$(RESET)"
	@echo "$(RED)⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀$(RESET)"
	@echo "$(RED)⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀$(RESET)"
	@echo "$(RED)⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀$(RESET)"
	@echo "$(RED)⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀$(RESET)"
	@echo "$(RED)⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀$(RESET)"
	@echo "$(RED)⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀$(RESET)"
	@echo "$(RED)⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀$(RESET)"
	@echo "$(RED)⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(RESET)"

.PHONY: all clean fclean re debug tests_run coverage
