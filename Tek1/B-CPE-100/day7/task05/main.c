/*
** EPITECH PROJECT, 2024
** main
** File description:
** print the arguments in reverse
*/

void my_putchar(char c);
int my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return 0;
}
