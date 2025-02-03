/*
** EPITECH PROJECT, 2024
** cat
** File description:
** cat
*/

#include <fcntl.h>
#include "rush3.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void displays_length(int length, int height)
{
    my_putchar(' ');
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
}

static void displays_name(char *rush_name, int length, int height)
{
    my_putstr(rush_name);
    displays_length(length, height);
    my_putchar('\n');
}

int my_put_exceptions2(char *buff, int length, int height)
{
    if (height == 1 && buff[length] == 'C') {
        my_putstr("[rush1-4]");
        displays_length(length, height);
        my_putstr(" || [rush1-5]");
        displays_length(length, height);
        my_putchar('\n');
        return 1;
    } else if (length == 1 && buff[height] == 'A') {
        my_putstr("[rush1-3]");
        displays_length(length, height);
        my_putchar('\n');
        return 1;
    }
    return 0;
}

int my_put_exceptions1(char *buff, int length, int height)
{
    if (length == 1 && buff[height] == 'C') {
        my_putstr("[rush1-3]");
        displays_length(length, height);
        my_putstr(" || [rush1-5]");
        displays_length(length, height);
        my_putchar('\n');
        return 1;
    } else if (length == 1 && buff[height] == 'A') {
        my_putstr("[rush1-4]");
        displays_length(length, height);
        my_putchar('\n');
        return 1;
    }
    return my_put_exceptions2(buff, length, height);
}

int my_put_exceptions(char *buff, int length, int height)
{
    if ((length == 2 && height == 1
        && buff[0] == 'B' && buff[1] == 'B') ||
        (length == 1 && height == 1 && buff[0] == 'B') ||
        (height == 2 && length == 1
        && buff[0] == 'B' && buff[2] == 'B')){
        my_putstr("[rush1-3]");
        displays_length(length, height);
        my_putstr(" || [rush1-4]");
        displays_length(length, height);
        my_putstr(" || [rush1-5]");
        displays_length(length, height);
        my_putchar('\n');
        return 1;
    }
    return my_put_exceptions1(buff, length, height);
}

int rush3(char *buff)
{
    int length = 0;
    int height = 0;
    char *rush_name = malloc(sizeof(char) * 100);

    for (int i = 0; buff[i] != '\0'; i++) {
        if (length == 0 && buff[i] == '\n')
            length = i;
        if (buff[i] == '\n')
            height++;
    }
    if (length <= 0 || height <= 0 ||
        my_strcmp(check_name(buff, length, height), "none") == 0) {
        write(2, "none", 5);
        return 84;
    }
    rush_name = check_name(buff, length, height);
    if ((my_put_exceptions(buff, length, height) == 0)) {
        displays_name(rush_name, length, height);
    }
    return 0;
}
