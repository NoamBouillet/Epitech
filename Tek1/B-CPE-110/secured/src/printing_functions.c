/*
** EPITECH PROJECT, 2024
** my_printing
** File description:
** displays the characters of a string
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        l++;
    }
    return l;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

void my_put_nbr(int nbr)
{
    if (nbr >= 10)
        my_put_nbr(nbr / 10);
    my_putchar((nbr % 10) + '0');
}

char *my_strdup(const char *src)
{
    char *dup = NULL;
    int len = 0;

    while (src[len] != '\0')
        len++;
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return NULL;
    for (int i = 0; i <= len; i++)
        dup[i] = src[i];
    return dup;
}
