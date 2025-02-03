/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** prints a character
*/

#include <unistd.h>
#include "rush3.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
