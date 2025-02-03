/*
** EPITECH PROJECT, 2024
** lib_functions
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int l = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
        l++;
    return l;
}
