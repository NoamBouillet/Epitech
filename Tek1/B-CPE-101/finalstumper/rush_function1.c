/*
** EPITECH PROJECT, 2024
** rush_function
** File description:
** contains the fonctions of my rush 1
*/

#include <unistd.h>
#include "rush3.h"
#include <stdlib.h>

static void exceptions(int columns, int ligns, char **buffer)
{
    if (columns == 1 && ligns == 1) {
        my_strcat((*buffer), "o\n");
        return;
    }
    if (columns == 1) {
        my_strcat((*buffer), "o\n");
        for (int i = 1; i <= ligns - 2; i++)
            my_strcat((*buffer), "|\n");
        my_strcat((*buffer), "o\n");
        return;
    }
    if (ligns == 1) {
        my_strcat((*buffer), "o");
        for (int i = 1; i <= columns - 2; i++)
            my_strcat((*buffer), "-");
        my_strcat((*buffer), "o\n");
        return;
    } else {
        write(2, "Invalid size\n", 14);
    }
}

static void extrems(int j, int ligns, int columns, char **buffer)
{
    if (j == 1) {
        my_strcat((*buffer), "o");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "-");
        my_strcat((*buffer), "o\n");
        return;
    }
    if (j == ligns) {
        my_strcat((*buffer), "o");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "-");
        my_strcat((*buffer), "o\n");
        return;
    } else {
        my_strcat((*buffer), "|");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), " ");
        my_strcat((*buffer), "|\n");
        return;
    }
}

char *rush_function1(int x, int y)
{
    char *buffer = malloc(sizeof(char) *50000);

    if (x <= 1 || y <= 1) {
        exceptions(x, y, &buffer);
        return buffer;
    }
    for (int j = 1; j <= y; j++) {
        extrems(j, y, x, &buffer);
    }
    return buffer;
}
