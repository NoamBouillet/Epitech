/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** Takes a number, returns N if the number is negative, else return P
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
