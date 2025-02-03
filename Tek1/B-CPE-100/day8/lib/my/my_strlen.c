/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** returns the number of characters found in a string
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        l++;
    }
    return l;
}
