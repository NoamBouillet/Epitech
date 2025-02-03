/*
** EPITECH PROJECT, 2024
** star_options
** File description:
** star functions
*/

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

void my_little_star(void)
{
    my_putstr("   *\n");
    my_putstr("*** ***\n");
    my_putstr(" *   *\n");
    my_putstr("*** ***\n");
    my_putstr("   *\n");
}

void star_body2(unsigned int size, int orientation, int i)
{
    if (orientation == 1) {
        for (int k = 1; k <= i; k++) {
            my_putchar(' ');
    }
        my_putchar('*');
        for (int k = 0; k < 6 * size -2 * i -3; k++) {
            my_putchar(' ');
        }
        my_putstr("*\n");
    } else {
        for (int k = 1; k <= (size - i); k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int k = 0; k < 6 * (size) -2 * (size - i) -3; k++) {
        my_putchar(' ');
    }
        my_putchar('*');
    my_putchar('\n');
    }
}

void star_head2(unsigned int size, int orientation, int i)
{
    if (orientation == 1) {
        for (int k = 1; k <= (3 * size - 1 - i); k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int k = 0; k < 2 * i - 1; k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    } else {
        for (int k = 1; k < (2 * size + i); k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int k = 0; k < 2 * (size - i) -1; k++) {
            my_putchar(' ');
    }
        my_putstr("*\n");
    }
}

void star_body(unsigned int size, int orientation)
{
    for (int i = 1; i < size; i++) {
        star_body2(size, orientation, i);
    }
}
