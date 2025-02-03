/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** checks if a string is in uppercase letters
*/

int my_str_checks_for_lowercase(char const *str, int i)
{
    if (str[i] >= 65 && str[i] <= 90) {
            return 1;
        }
    return 0;
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_str_checks_for_lowercase(str, i) == 0)
            return 0;
        i++;
    }
    return 1;
}
