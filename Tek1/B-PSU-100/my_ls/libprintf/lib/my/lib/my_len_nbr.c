/*
** EPITECH PROJECT, 2024
** my_len_nbr
** File description:
** returns the len of a number
*/

#include <stdio.h>
#include "../../../include/my.h"

int my_len_nbr(int nb)
{
    int cpt = 0;

    if (nb <= 0) {
        nb = nb * -1;
    }
    while (nb >= 1) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}

int my_len_longint(unsigned long int nbr)
{
    int cpt = 0;

    if (nbr <= 0) {
        nbr = nbr * -1;
    }
    while (nbr >= 1) {
        nbr = nbr / 10;
        cpt++;
    }
    return cpt;
}

int minimum(int length, int precision)
{
    if (length >= precision && precision != 6)
        return precision;
    return length;
}

int maximum(int first_nbr, int second_nbr)
{
    if (first_nbr >= second_nbr)
        return first_nbr;
    return second_nbr;
}
