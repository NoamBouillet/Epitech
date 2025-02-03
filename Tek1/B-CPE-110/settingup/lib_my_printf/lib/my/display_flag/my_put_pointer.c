/*
** EPITECH PROJECT, 2024
** my_put_pointer.c
** File description:
** displays the adress of a pointer
*/

#include "../../../include/my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int is_letters(long nb)
{
    long letter;

    if (nb >= 10) {
        letter = nb + 7;
    } else {
        letter = nb;
    }
    return letter;
}

static int shows_hexa_ptr(long nb, cursor_t *cursor, flag_properties_t var)
{
    long quotient = nb;
    char *str = malloc(sizeof(char) * 50);
    int i = 0;

    while (quotient != 0) {
        str[i] = is_letters(quotient % 16) + 48;
        quotient = quotient / 16;
        i++;
    }
    display_width(my_strlen(str) + 2, var, cursor, 0);
    (*cursor).length += my_printf("0x");
    cursor += my_printf(my_strlowcase(my_revstr(str)));
    width_left(my_strlen(str) + 2, var, cursor, 0);
    (*cursor).i++;
    return i;
}

int my_put_pointer(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    void *ptr = va_arg(list_arguments, void *);

    if (ptr == NULL) {
        my_printf("(nil)");
        return 0;
    }
    (*cursor).length += shows_hexa_ptr
        ((long int)ptr, cursor, var);
    return 0;
}
