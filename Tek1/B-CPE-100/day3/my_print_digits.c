/*
** EPITECH PROJECT, 2024
** my_print_digits
** File description:
** displays all digits in ascending order
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = 48; i < 58; i++) {
        my_putchar(i);
    }
    return 0;
}
