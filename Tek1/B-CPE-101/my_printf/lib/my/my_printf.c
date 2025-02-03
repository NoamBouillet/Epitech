/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** reproduces the printf functio,
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"
#include <stdlib.h>

int search_flag(const char *format, cursor_t *cursor,
    va_list list_arguments)
{
    flag_properties_t var;

    var.flag = my_flag(format, cursor);
    var.width = my_width(format, cursor);
    var.precision = my_precision(format, cursor);
    var.length = my_length(format, cursor);
    var.specifier = my_speci(format, cursor);
    if (check_flag(var) == 84) {
        write(2, "Wrong flag specified", 21);
        return 84;
    }
    my_flag_gestion(var, cursor, list_arguments);
    return 0;
}

int through_function(const char *format, cursor_t *cursor,
    va_list list_arguments)
{
    if (format[(*cursor).i] == '%') {
        (*cursor).i++;
        if (search_flag(format, cursor, list_arguments) == 84)
            return 84;
    } else {
        my_putchar(format[(*cursor).i]);
        (*cursor).length++;
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));
    va_list list_arguments;

    cursor->length = 0;
    cursor->i = 0;
    va_start(list_arguments, *format);
    for (; cursor->i < my_strlen(format); cursor->i++) {
        if (through_function(format, cursor, list_arguments) == 84)
            return 84;
    }
    va_end(list_arguments);
    return cursor->length;
}
