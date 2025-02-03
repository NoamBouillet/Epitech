/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

#include "../../../include/my.h"
#include <stdio.h>

static int check_for_0(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    return 0;
}

static int my_put_nbr_printf(int nb, int length)
{
    if (check_for_0(nb) != 0){
        return length + 1;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        length++;
    }
    if (nb < 10) {
        my_putchar(48 + nb);
        return length + 1;
    }
    length++;
    my_put_nbr_printf((nb / 10), length);
    my_putchar(48 + nb % 10);
    return length;
}

int my_put_nbr(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    int number;
    int has_sign;

    if ((var.length)[0] == 'l')
        return my_put_longint(var, cursor, list_arguments);
    number = va_arg(list_arguments, int);
    has_sign = (number >= 0 && (var.flag == '+' || var.flag == ' '));
    if (number <= 0)
        has_sign++;
    display_width(my_len_nbr(number), var, cursor, has_sign);
    flag_plus(number, var, cursor);
    (*cursor).length += my_put_nbr_printf(number, 0);
    width_left(my_len_nbr(number), var, cursor, has_sign);
    return 0;
}
