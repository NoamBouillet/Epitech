/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compares two strings
*/

#include "rush3.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
