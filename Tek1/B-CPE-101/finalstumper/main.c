/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** finalstumper
*/

#include <unistd.h>
#include "rush3.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush3.h"

//Tant que la longueur du buffer est plus grand que 0 on rajoute len à l'offset
//On actionne rush3 avec pour paramètre le buffer
// ./rush1-3 2 2 | ./rush3

int main(void)
{
    char buff[32000 + 1];
    int offset = 0;
    int len;

    len = read(0, buff + offset, 32000 - offset);
    while (len > 0) {
        offset = offset + len;
        len = read(0, buff + offset, 32000 - offset);
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return 0;
}
