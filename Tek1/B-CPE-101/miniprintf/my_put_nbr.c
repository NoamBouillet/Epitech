/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

#include "my.h"

static int my_put_nbr_printf(int nb, int length)
{
    if (nb == 0) {
        my_putchar('0');
        return length + 1;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        length++;
    }
    if (nb >= 10) {
        length = my_put_nbr_printf(nb / 10, length);
    }
    my_putchar(48 + nb % 10);
    return length + 1;
}

int my_put_nbr(int nb)
{
    return my_put_nbr_printf(nb, 0);
}
