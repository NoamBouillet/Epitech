/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** returns 1 if all characters are lowercase alphabet letters
*/

int my_str_checks_lowercase(char const *str, int i)
{
    if (str[i] >= 97 && str[i] <= 122) {
            return 1;
        }
    return 0;
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_str_checks_lowercase(str, i) == 0)
            return 0;
        i++;
    }
    return 1;
}
