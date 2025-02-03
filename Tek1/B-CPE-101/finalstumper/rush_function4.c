/*
** EPITECH PROJECT, 2024
** rush_function
** File description:
** second assignment
*/

#include <unistd.h>
#include "rush3.h"
#include <stdlib.h>

static void exceptions(int columns, int ligns, char **buffer)
{
    if (columns == 1) {
        for (int i = 1; i <= ligns; i++) {
            my_strcat((*buffer), "B\n");
        }
        return;
    }
    if (ligns == 1) {
        for (int i = 1; i <= columns; i++) {
            my_strcat((*buffer), "B");
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
        my_strcat((*buffer), "A");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "B");
        my_strcat((*buffer), "C\n");
        return;
    }
    if (j == ligns) {
        my_strcat((*buffer), "A");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), "B");
        my_strcat((*buffer), "C\n");
        return;
    } else {
        my_strcat((*buffer), "B");
        for (int l = 0; l < columns - 2; l++)
            my_strcat((*buffer), " ");
        my_strcat((*buffer), "B\n");
        return;
    }
}

char *rush_function4(int x, int y)
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
