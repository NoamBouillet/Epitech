/*
** EPITECH PROJECT, 2024
** my_my_strdup
** File description:
** copies a string into allocated memory
*/

#include <stdlib.h>
#include "../../../include/my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int index = 0;

    for (int i = 0; i < len; i++) {
        str[i] = src[i];
        index++;
    }
    str[index] = '\0';
    return str;
}
