/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** reproduces strncmp
*/

#include <stddef.h>

int testing2(char const *s1, char const *s2, int *array)
{
    int advance = 0;

    for (int j = 0; (j < array[2]) && (s1[j] == s2[j]); j++) {
            if (s1[j] == '\0' || s2[j] == '\0')
                return 0;
            advance++;
    }
    if (s1[advance] > s2[advance])
        return 1;
    return -1;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int l = 0;
    int l2 = 0;
    int array[3];

    if (n == 0)
        return 0;
    for (int i = 0; s1[i] != '\0'; i++)
        l++;
    for (int i = 0; s2[i] != '\0'; i++)
        l2++;
    array[0] = l;
    array[1] = l2;
    array[2] = n;
    return testing2(s1, s2, array);
}
