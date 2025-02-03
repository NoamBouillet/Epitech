/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** checks if a string only contains letters
*/

int my_str_checks_alpha(char const *str, int i)
{
    if ((str[i] >= 65 && str[i] <= 90)
        || (str[i] >= 97 && str[i] <= 122)) {
            return 1;
        }
    return 0;
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_str_checks_alpha(str, i) == 0)
            return 0;
        i++;
    }
    return 1;
}
