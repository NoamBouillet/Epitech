/*
** EPITECH PROJECT, 2024
** my_put_hexa
** File description:
** hexa number
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

static int is_letters(int nb)
{
    int letter;

    if (nb >= 10) {
        letter = nb + 7;
    } else {
        letter = nb;
    }
    return letter;
}

static void display_lowercase(char *str,
    cursor_t *cursor, int has_sign, flag_properties_t var)
{
    my_putstr_basic((my_strlowcase(str)), cursor);
    width_left(my_strlen(str), var, cursor, has_sign);
    free(str);
}

static int turns_to_hexa(int nb, int length,
    cursor_t *cursor, flag_properties_t var)
{
    unsigned int quotient = (unsigned int)nb;
    char *str = malloc(sizeof(char) * 50);
    int i = 0;
    int has_sign = value_flag(var);

    while (quotient != 0) {
        str[i] = is_letters(quotient % 16) + 48;
        quotient = quotient / 16;
        i++;
    }
    display_width(my_strlen(str), var, cursor, has_sign);
    flag_sharp(var, cursor);
    if (var.specifier == 'x') {
        display_lowercase(my_revstr(str), cursor, has_sign, var);
        return length;
    }
    my_putstr_basic(my_revstr(str), cursor);
    width_left(my_strlen(str), var, cursor, has_sign);
    free(str);
    return length;
}

int my_put_hexa(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    int arg = va_arg(list_arguments, int);

    if (arg == 0) {
        my_putchar('0');
        cursor->length++;
        return 0;
    }
    (*cursor).length += turns_to_hexa
        (arg, 0, cursor, var);
    return 0;
}
