/*
** EPITECH PROJECT, 2024
** my_put_percent
** File description:
** displays a single percent
*/

#include "../../../include/my.h"
#include <stdarg.h>

int my_put_length(__attribute__((unused))flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    *(va_arg(list_arguments, int *)) = (*cursor).length;
    return 0;
}
