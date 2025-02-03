/*
** EPITECH PROJECT, 2024
** my_str_is_printable
** File description:
** returns 1 if the string is made of printable characters
*/

int my_str_checks_printable(char const *str, int i)
{
    if (str[i] >= 32 && str[i] <= 126) {
            return 1;
        }
    return 0;
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_str_checks_printable(str, i) == 0)
            return 0;
        i++;
    }
    return 1;
}
