/*
** EPITECH PROJECT, 2024
** absolute value function
** File description:
** absolute_value
*/

double absolute_value(double incidence)
{
    if (incidence < 0)
        incidence = incidence * -1;
    return incidence;
}
