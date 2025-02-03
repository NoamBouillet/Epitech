/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** prints a character
*/

#include <unistd.h>
#include "../../../include/my.h"
#include <stdio.h>

int my_putchar_buffer(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    char c = va_arg(list_arguments, int);

    while (var.width > 1 && var.flag != '-') {
        my_putchar(' ');
        cursor->length++;
        var.width--;
    }
    (*cursor).length++;
    write(1, &c, 1);
    while (var.width > 1 && var.flag == '-') {
        my_putchar(' ');
        cursor->length++;
        var.width--;
    }
    return 0;
}
