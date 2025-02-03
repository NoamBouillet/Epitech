/*
** EPITECH PROJECT, 2024
** my_strisnum
** File description:
** checks if the string only contains numbers
*/

#include "../../../include/my.h"

static int my_str_checks_num(char const *str, int i)
{
    if (str[i] > 57 || str[i] < 48) {
            return 0;
        }
    return 1;
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_str_checks_num(str, i) == 0)
            return 0;
        i++;
    }
    return 1;
}
