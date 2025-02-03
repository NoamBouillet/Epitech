/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** does the printf functions for basic flags
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>
#include <stdio.h>

int *my_execution2(const char *format, int *i,
    va_list list_arguments, int *length)
{
    if (format[(*i)] == '%' && format[(*i) + 1] == 's') {
        (*length) += my_putstr(va_arg(list_arguments, char *));
        (*i) = (*i) + 1;
        return length;
    }
    if (format[(*i)] == '%' && (format[(*i) + 1] == 'd'
        || format[(*i) + 1] == 'i')) {
        (*length) += my_put_nbr(va_arg(list_arguments, int));
        (*i) = (*i) + 1;
        return length;
    }
    if (format[(*i)] == '%' && format[(*i) + 1] == '%') {
        (*i) = (*i);
        return length;
    }
    return NULL;
}

int my_execution(const char *format, int *i,
    va_list list_arguments, int *length)
{
    if (my_execution2(format, i, list_arguments, length) == NULL) {
        if (format[(*i)] == '%' && format[(*i) + 1] == 'c') {
            my_putchar(va_arg(list_arguments, int));
            (*i) = (*i) + 1;
            (*length) ++;
        } else {
            my_putchar(format[*i]);
            (*length)++;
        }
    }
    return *i;
}

int mini_printf(const char *format, ...)
{
    va_list list_arguments;
    int length = 0;

    va_start(list_arguments, *format);
    for (int i = 0; i < my_strlen(format); i++) {
        my_execution(format, &i, list_arguments, &length);
    }
    va_end(list_arguments);
    return length;
}
