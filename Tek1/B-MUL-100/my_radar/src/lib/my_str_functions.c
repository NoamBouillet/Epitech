/*
** EPITECH PROJECT, 2025
** lib_functions
** File description:
** useful functions made for the project
*/

#include "../include/my_radar.h"

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

int my_strlen(char const *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++)
        l++;
    return l;
}

int str_toi(const char *str)
{
    int result = 0;
    int i = 0;

    if (str[i] == '-') {
        return -1;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *new_dest = malloc(dest_len + src_len + 1);

    if (!new_dest)
        return NULL;
    for (int i = 0; i < dest_len; i++) {
        new_dest[i] = dest[i];
    }
    for (int j = 0; j < src_len; j++) {
        new_dest[dest_len + j] = src[j];
    }
    new_dest[dest_len + src_len] = '\0';
    return new_dest;
}
