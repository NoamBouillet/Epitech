/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** int_to_string
*/

#include <stdlib.h>

int my_len_nbr(int nb)
{
    int cpt = (nb <= 0) ? 1 : 0;

    while (nb != 0) {
        nb /= 10;
        cpt++;
    }
    return cpt;
}

int my_strlen(char const *str)
{
    int l = 0;

    while (str[l] != '\0')
        l++;
    return l;
}

static char *my_strcatchar(char *dest, char const character)
{
    int k = my_strlen(dest);

    dest[k] = character;
    dest[k + 1] = '\0';
    return dest;
}

static char *add_to_string(int nb, char *str)
{
    if (nb < 0) {
        str = my_strcatchar(str, '-');
        nb = -nb;
    }
    if (nb >= 10) {
        str = add_to_string(nb / 10, str);
    }
    str = my_strcatchar(str, '0' + nb % 10);
    return str;
}

char *turns_int_to_string(int nb)
{
    int length = my_len_nbr(nb);
    char *string_nbr = malloc(sizeof(char) * (length + 1));

    string_nbr[0] = '\0';
    return add_to_string(nb, string_nbr);
}
