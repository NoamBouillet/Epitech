/*
** EPITECH PROJECT, 2024
** my_flag
** File description:
** rechercher de flag
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../../include/my.h"

char my_flag(const char *format, cursor_t *cursor)
{
    char flags_list[] = {'-', '0', ' ', '+', '#', '\0'};
    char caractere = format[(*cursor).i];
    int a = 0;

    while (flags_list[a] != '\0') {
        if (flags_list[a] == caractere) {
            (*cursor).i++;
            return flags_list[a];
        }
        a++;
    }
    return 0;
}
