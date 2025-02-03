/*
** EPITECH PROJECT, 2024
** main
** File description:
** executes the functions
*/

void my_putchar(char c);
int my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return 0;
}
