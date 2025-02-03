/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it
** File description:
** returns the factorial of a number
*/

int fact(int n)
{
    int result = 1;

    if (n > 12)
        return 0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int my_compute_factorial_it(int nb)
{
    if (nb < 0)
        return 0;
    if (nb == 0)
        return 1;
    return fact(nb);
}
