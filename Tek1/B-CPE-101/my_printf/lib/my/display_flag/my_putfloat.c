/*
** EPITECH PROJECT, 2024
** my_putfloat
** File description:
** displays a float
*/

#include <stdio.h>
#include "../../../include/my.h"
#include <stdarg.h>

static int displays_precision(long int nb, int cpt)
{
    if (nb < 1000000) {
        my_putchar('0');
        cpt++;
    }
    if (nb < 100000) {
        my_putchar('0');
        cpt++;
    }
    if (nb < 10000) {
        my_putchar('0');
        cpt++;
    }
    return cpt;
}

static int displays_precision_bis(long int nb, int cpt)
{
    if (nb < 1000) {
        my_putchar('0');
        cpt++;
    }
    if (nb < 100) {
        my_putchar('0');
        cpt++;
    }
    return cpt;
}

static void is_neg(double *nbr, cursor_t *cursor)
{
    if ((*nbr) < 0) {
        my_putchar('-');
        (*nbr) = (*nbr) * -1;
        (*cursor).length++;
    }
}

static int round_up(int nb, int cpt)
{
    int nb_bis = nb;
    int pre;

    if (my_len_nbr(nb_bis) >= 7 - cpt) {
        pre = nb_bis % 10;
        if ((pre) >= 5) {
            return nb_bis / 10 + 1;
        }
        nb_bis = nb_bis / 10;
    }
    return nb_bis;
}

int my_putfloat(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    double nbr = va_arg(list_arguments, double);
    int integer_part;
    int cpt = 0;
    long int decimal_part;
    int has_sign = maximum((var.flag == ' '), (var.flag == '+'));

    is_neg(&nbr, cursor);
    integer_part = (int)nbr;
    decimal_part = (long int)(nbr * 10000000 - integer_part * 10000000);
    display_width(my_len_nbr(integer_part) + 7, var, cursor, has_sign);
    flag_plus((int)nbr, var, cursor);
    (*cursor).length += my_printf("%d.", integer_part);
    cpt += displays_precision(decimal_part, cpt);
    cpt += displays_precision_bis(decimal_part, cpt) - cpt;
    decimal_part = round_up(decimal_part, cpt);
    (*cursor).length += my_printf("%d", decimal_part) + 1;
    width_left(my_len_nbr(integer_part) + 7, var, cursor, has_sign);
    return 0;
}
