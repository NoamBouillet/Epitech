/*
** EPITECH PROJECT, 2024
** test_my_put_nbr
** File description:
** tests my_put_nbr
*/

#include <limits.h>
int my_put_nbr(int);

void my_putchar(char);

int main(void)
{
    my_put_nbr(-2147483648);
    my_putchar('\n');
    my_put_nbr(1);
    my_putchar('\n');
    my_put_nbr(-1);
    my_putchar('\n');
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(2147483647);
    my_putchar('\n');
}
