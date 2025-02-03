/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** raises a number to a power
*/

int my_compute_power_it(int nb, int p)
{
    long sec_number = nb;
    int return2;

    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    for (int i = 1; i < p; i++) {
        sec_number *= nb;
    }
    if (sec_number < -2147483648 || sec_number > 2147483647)
        return 0;
    return2 = (int)sec_number;
    return return2;
}
