/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swaps the content of two integers
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}
