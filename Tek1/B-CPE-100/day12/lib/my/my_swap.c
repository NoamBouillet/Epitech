/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swaps the content of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}
