/*
** EPITECH PROJECT, 2024
** my_put_percent
** File description:
** put percent specifier
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../../include/my.h"
#include <stdio.h>

int my_put_percent(__attribute__((unused))flag_properties_t var,
    cursor_t *cursor, __attribute__((unused))va_list list_arguments)
{
    (*cursor).length += 1;
    my_putchar('%');
    return 0;
}
