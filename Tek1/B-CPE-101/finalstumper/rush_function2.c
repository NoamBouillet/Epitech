/*
** EPITECH PROJECT, 2024
** rush_function
** File description:
** second assignment
*/

#include <unistd.h>
#include <stdlib.h>
#include "rush3.h"

static void exceptions(int columns, int ligns, char **buffer)
{
    if (columns == 1) {
        for (int i = 1; i <= ligns; i++) {
            my_strcat((*buffer), "*\n");
        }
        return;
    }
    if (ligns == 1) {
        for (int i = 1; i <= columns; i++) {
            my_strcat((*buffer), "*");
        }
        my_strcat((*buffer), "\n");
        return;
    } else {
        write(2, "Invalid size\n", 14);
    }
}

static void extrems(int j, int ligns, int columns, char **buffer)
{
    if (j == 1) {
        my_strcat((*buffer), "/");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "*");
        my_strcat((*buffer), "\\\n");
        return;
    }
    if (j == ligns) {
        my_strcat((*buffer), "\\");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "*");
        my_strcat((*buffer), "/\n");
        return;
    } else {
        my_strcat((*buffer), "*");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), " ");
        my_strcat((*buffer), "*\n");
        return;
    }
}

char *rush_function2(int x, int y)
{
    char *buffer = malloc(sizeof(char) * 10000);

    if (x <= 1 || y <= 1) {
        exceptions(x, y, &buffer);
        return buffer;
    }
    for (int j = 1; j <= y; j++) {
        extrems(j, y, x, &buffer);
    }
    return buffer;
}
