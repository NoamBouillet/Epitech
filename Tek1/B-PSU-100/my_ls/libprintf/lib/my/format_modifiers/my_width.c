/*
** EPITECH PROJECT, 2024
** my_width
** File description:
** determines the width
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int my_width(const char *format, cursor_t *cursor)
{
    int a = my_getnbr(format, (*cursor).i);

    (*cursor).i += my_len_nbr(a);
    if (a > INT_MAX) {
        write(1, "too big of a width", 19);
        return 84;
    }
    return a;
}
