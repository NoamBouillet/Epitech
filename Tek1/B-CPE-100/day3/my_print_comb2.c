/*
** EPITECH PROJECT, 2024
** my_print_comb2
** File description:
** displays in ascending order, combinations of two digits
*/

void my_putchar(char c);

int n1;
int n2;
int n3;
int n4;

int my_comma(int i, int j)
{
    if (i != 98 || j != 99) {
                my_putchar(',');
                my_putchar(' ');
            } else {
                my_putchar('\n');
            }
    return 0;
}

int my_print_comb2(void)
{
    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            n1 = 48 + i % 10;
            n2 = 48 + i / 10;
            my_putchar(n2);
            my_putchar(n1);
            my_putchar(' ');
            n3 = 48 + j % 10;
            n4 = 48 + j / 10;
            my_putchar(n4);
            my_putchar(n3);
            my_comma(i, j);
        }
    }
    return 0;
}
