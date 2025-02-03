/*
** EPITECH PROJECT, 2024
** my_put_octal
** File description:
** put octal
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../../include/my.h"
#include <stdio.h>

static int my_putstr_basic(char *str, cursor_t *cursor)
{
    int l = write(1, str, my_strlen(str));

    (*cursor).length += l;
    return 0;
}

static int turns_to_octal(int nb, int length, cursor_t *cursor
    , flag_properties_t var)
{
    unsigned int quotient = (unsigned int)nb;
    char *str = malloc(sizeof(char) * 50);
    int i = 0;
    int has_sign = value_flag(var);

    for (; quotient != 0; i++) {
        str[i] = quotient % 8 + 48;
        quotient = quotient / 8;
    }
    str[i] = '\0';
    display_width(my_strlen(str), var, cursor, has_sign);
    flag_sharp(var, cursor);
    my_putstr_basic(my_revstr(str), cursor);
    width_left(my_strlen(str), var, cursor, has_sign);
    free(str);
    return length;
}

int my_put_octal(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    int arg = va_arg(list_arguments, int);

    if (arg == 0) {
        my_putchar('0');
        cursor->length++;
        return 0;
    }
    (*cursor).length += turns_to_octal
        (arg, 0, cursor, var);
    return 0;
}
