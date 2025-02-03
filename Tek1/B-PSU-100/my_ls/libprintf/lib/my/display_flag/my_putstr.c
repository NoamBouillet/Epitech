/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** displays the characters of a string
*/

#include "../../../include/my.h"
#include <unistd.h>

static void width_str(char *str, flag_properties_t var, cursor_t *cursor)
{
    while (var.width > minimum(my_strlen(str), var.precision)
        && var.flag != '-') {
        my_putchar(' ');
        cursor->length++;
        var.width--;
    }
}

int my_putstr(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    char *str = va_arg(list_arguments, char *);

    if (str == NULL) {
        return 84;
        write(2, "(null)", 6);
    }
    width_str(str, var, cursor);
    for (int i = 0; str[i] != '\0' && !(var.precision != 6
        && var.precision == i); i++) {
        my_putchar(str[i]);
        (*cursor).length += 1;
    }
    while (var.width > minimum(my_strlen(str)
        , var.precision) && var.flag == '-') {
        my_putchar(' ');
        cursor->length++;
        var.width--;
    }
    return 0;
}
