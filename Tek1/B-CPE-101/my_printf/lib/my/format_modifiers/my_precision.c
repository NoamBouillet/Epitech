/*
** EPITECH PROJECT, 2024
** my_precision
** File description:
** determines the precision of a flag
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>
#include <unistd.h>

int my_precision(const char *format, cursor_t *cursor)
{
    char caractere = format[(*cursor).i];
    int a = 6;

    if (caractere == '.') {
        a = my_getnbr(format, (*cursor).i + 1);
        (*cursor).i++;
    }
    if (a > 17) {
        (*cursor).i += my_len_nbr(a);
        return 84;
    }
    if (a != 6)
        (*cursor).i += my_len_nbr(a);
    return a;
}
