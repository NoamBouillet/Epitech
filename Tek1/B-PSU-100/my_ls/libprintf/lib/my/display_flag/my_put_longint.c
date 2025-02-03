/*
** EPITECH PROJECT, 2024
** my_put_longint
** File description:
** unsigned value of int
*/


#include "../../../include/my.h"
#include <stdio.h>

static int check_for_0(unsigned long int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    return 0;
}

static int my_put_longint_printf(unsigned long int nb, int length)
{
    if (check_for_0(nb) != 0){
        return check_for_0(nb);
    }
    if (nb < 10) {
        my_putchar(48 + nb);
        return length + 1;
    }
    length++;
    my_put_longint_printf((nb / 10), length);
    my_putchar(48 + nb % 10);
    return length;
}

int my_put_longint(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    unsigned long int nbr = va_arg(list_arguments, unsigned long int);
    int has_sign = 0;

    display_width(my_len_longint(nbr), var, cursor, has_sign);
    (*cursor).length += my_put_longint_printf(nbr, 0);
    width_left(my_len_longint(nbr), var, cursor, has_sign);
    return 0;
}
