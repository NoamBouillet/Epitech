/*
** EPITECH PROJECT, 2024
** my_length
** File description:
** determines the length of a flag
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>
#include <unistd.h>

char *my_length(const char *format, cursor_t *cursor)
{
    static char *length_list[] = {"hh", "ll"};
    static char *length_list_second[] = {"l", "q", "j", "z", "Z", "t", "h"};
    char caractere = format[cursor->i];

    for (int i = 0; i < 2; i++) {
        if (format[(*cursor).i] == length_list[i][0] &&
            format[(*cursor).i + 1] == length_list[i][1]) {
            cursor->i += 2;
            return length_list[i];
        }
    }
    for (int i = 0; i < 7; i++) {
        if (caractere == length_list_second[i][0]) {
            (*cursor).i += 1;
            return length_list_second[i];
        }
    }
    return "";
}
