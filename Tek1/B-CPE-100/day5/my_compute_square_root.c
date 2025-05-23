/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** returns the square root of a number
*/

int my_compute_power_it(int nb, int p);

int my_compute_square_root(int nb)
{
    int i = 1;

    while (my_compute_power_it(i, 2) < nb) {
        i++;
    }
    if (my_compute_power_it(i, 2) == nb)
        return i;
    return 0;
}
