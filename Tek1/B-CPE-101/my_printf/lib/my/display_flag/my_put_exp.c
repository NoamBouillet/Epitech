/*
** EPITECH PROJECT, 2024
** my_put_exp
** File description:
** specifiers %e and %E
*/

#include <stdio.h>
#include "../../../include/my.h"

double check(double nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        return nb;
    }
    return nb;
}

int inf_zero(double nbr, int cpt, char c)
{
    if (1 > nbr && nbr > 0) {
        while (nbr < 1) {
            nbr = nbr * 10;
            cpt++;
        }
        my_printf("%f", nbr);
        if (cpt <= 9) {
            my_printf("%c%c%d%d", c, '-', 0, cpt);
            return 0;
        }
        my_printf("%c%c", c, '-');
        my_printf("%d", cpt);
        return 0;
    }
    return 0;
}

int sup_zero(double nbr, int cpt, char c)
{
    if (nbr >= 1 || nbr <= 0) {
        while (nbr >= 10) {
            nbr = nbr / 10;
            cpt++;
        }
        my_printf("%f", nbr);
        if (cpt <= 9) {
            my_printf("%c%c%d%d", c, '+', 0, cpt);
            return 0;
        }
        my_printf("%c%c%d", c, '+', cpt);
    }
    return 0;
}

int my_put_exp_printf(double nb, char c)
{
    int cpt = 0;
    double nbr = check(nb);

    inf_zero(nbr, cpt, c);
    sup_zero(nbr, cpt, c);
    return 0;
}

int my_put_exp(flag_properties_t var,
    __attribute__((unused))cursor_t *cursor, va_list list_arguments)
{
    char c;
    double nb = va_arg(list_arguments, double);

    if (var.specifier == 'E') {
        c = 'E';
    } else {
        c = 'e';
    }
    my_put_exp_printf(nb, c);
    return 0;
}
