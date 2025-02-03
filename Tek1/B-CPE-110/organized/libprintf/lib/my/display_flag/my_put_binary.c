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

static int turns_to_bin(int nb, int length, cursor_t *cursor)
{
    unsigned int quotient = (unsigned int)nb;
    char *str = malloc(sizeof(char) * 50);
    int i = 0;

    if (!str)
        return 84;
    for (; quotient != 0; i++) {
        str[i] = quotient % 2 + 48;
        quotient = quotient / 2;
    }
    str[i] = '\0';
    my_putstr_basic(my_revstr(str), cursor);
    free(str);
    return length;
}

int my_put_binary(__attribute__((unused))flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    int arg = va_arg(list_arguments, int);

    if (arg == 0) {
        my_putchar('0');
        cursor->length++;
        return 0;
    }
    (*cursor).length += turns_to_bin
        (arg, 0, cursor);
    return 0;
}
