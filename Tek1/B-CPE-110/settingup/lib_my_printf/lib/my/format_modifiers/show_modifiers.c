/*
** EPITECH PROJECT, 2024
** my_len_nbr
** File description:
** returns the len of a number
*/

#include <stdio.h>
#include "../../../include/my.h"

void display_width(int length, flag_properties_t var,
    cursor_t *cursor, int has_sign)
{
    int cut_length = minimum(length, var.precision);

    var.width -= has_sign;
    while (var.width > cut_length) {
        if ((var.flag) == '0') {
            my_putchar('0');
            cursor->length++;
            var.width--;
            continue;
        }
        if (var.flag != '-')
            my_putchar(' ');
        cursor->length++;
        var.width--;
    }
}

void width_left(int length, flag_properties_t var,
    cursor_t *cursor, int has_sign)
{
    int cut_length = minimum(length, var.precision);

    if (has_sign == 1)
        var.width--;
    while (var.width > cut_length && var.flag == '-') {
        my_putchar(' ');
        cursor->length++;
        var.width--;
    }
}

void flag_plus(int number, flag_properties_t var, cursor_t *cursor)
{
    if (number >= 0 && var.flag == '+') {
        my_putchar('+');
        cursor->length++;
    }
    if (number >= 0 && var.flag == ' ') {
        my_putchar(' ');
        cursor->length++;
    }
}

void flag_sharp(flag_properties_t var, cursor_t *cursor)
{
    if (var.flag == '#') {
        if (var.specifier == 'o') {
            my_printf("0");
            cursor->length++;
        }
        if (var.specifier == 'x') {
            my_printf("Ox");
            cursor->length += 2;
        }
        if (var.specifier == 'X') {
            my_printf("OX");
            cursor->length += 2;
        }
    }
}

int value_flag(flag_properties_t var)
{
    if (var.flag == '#') {
        if (var.specifier == 'o') {
            return 1;
        }
        if (var.specifier == 'x') {
            return 2;
        }
        if (var.specifier == 'X') {
            return 2;
        }
    }
    return 0;
}
