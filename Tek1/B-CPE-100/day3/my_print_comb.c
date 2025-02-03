/*
** EPITECH PROJECT, 2024
** my_print_comb
** File description:
** displays all the numbers composed by three different digits
*/

void my_putchar(char c);

int my_comma_and_space(int i, int j, int k)
{
    if (i != 55 || j != 56 || k != 57) {
        my_putchar(',');
        my_putchar(' ');
    }
    return 0;
}

int my_variables(int i, int j)
{
    for (int k = 48; k < 58; k++) {
        if (i < j && j < k) {
                my_putchar(i);
                my_putchar(j);
                my_putchar(k);
                my_comma_and_space(i, j, k);
                }
            }
    return 0;
}

int my_print_comb(void)
{
    for (int i = 48; i < 58; i++) {
        for (int j = 48; j < 58; j++) {
            my_variables(i, j);
            }
        }
    return 0;
}
