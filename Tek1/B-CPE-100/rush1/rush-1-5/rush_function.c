/*
** EPITECH PROJECT, 2024
** rush_function
** File description:
** second assignment
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        l++;
    }
    for (int h = 0; h < l; h++) {
        my_putchar(str[h]);
    }
    return 0;
}

void exceptions(int columns, int ligns)
{
    if (columns == 1) {
        for (int i = 1; i <= ligns; i++) {
            my_putstr("B\n");
        }
        return;
    }
    if (ligns == 1) {
        for (int i = 1; i <= columns; i++) {
            my_putstr("B");
        }
        my_putchar('\n');
        return;
    } else {
        write(2, "Invalid size\n", 14);
    }
}

void extrems(int j, int ligns, int columns)
{
    if (j == 1) {
        my_putchar('A');
        for (int l = 0; l < columns - 2; l++)
            my_putchar('B');
        my_putstr("C\n");
        return;
    }
    if (j == ligns) {
        my_putchar('C');
        for (int l = 0; l < columns - 2; l++)
            my_putchar('B');
        my_putstr("A\n");
        return;
    } else {
        my_putchar('B');
        for (int l = 0; l < columns - 2; l++)
            my_putchar(' ');
        my_putstr("B\n");
        return;
    }
}

void rush(int x, int y)
{
    if (x <= 1 || y <= 1) {
        exceptions(x, y);
        return;
    }
    for (int j = 1; j <= y; j++) {
        extrems(j, y, x);
    }
}
