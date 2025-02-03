/*
** EPITECH PROJECT, 2024
** my_print_revalpha
** File description:
** displays the alphabet in reverse order
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (int i = 122; i > 96; i--) {
        my_putchar(i);
    }
    return 0;
}
