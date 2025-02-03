/*
** EPITECH PROJECT, 2024
** my_speci
** File description:
** recherche specifier
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>

char my_speci(const char *format, cursor_t *cursor)
{
    char specifiers_list[] = {'c', 'd', 'i', 'f', 's', 'u', 'e', 'E'
    , 'o', 'x', 'X', 'g', 'G', 'p', 'n', '%', 'b', '\0'};
    char caractere = format[(*cursor).i];
    int a = 0;

    while (specifiers_list[a] != '\0') {
        if (specifiers_list[a] == caractere) {
            return specifiers_list[a];
        }
        a++;
    }
    return 84;
}
