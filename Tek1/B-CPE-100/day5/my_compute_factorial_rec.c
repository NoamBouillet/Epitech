/*
** EPITECH PROJECT, 2024
** my_compute_factorial_rec
** File description:
** recursive function returning the factorial of a number
*/

int my_compute_factorial_rec(int nb)
{
    if (nb > 12)
        return 0;
    if (nb < 0)
        return 0;
    if (nb == 0)
        return 1;
    return nb * my_compute_factorial_rec(nb - 1);
}
