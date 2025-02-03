/*
** EPITECH PROJECT, 2024
** my_evil_str
** File description:
** swaps the characters in a string
*/

void my_putchar(char c);

int my_len(char const *str)
{
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        l++;
    }
    return l;
}

char *my_evil_str(char *str)
{
    int length = my_len(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start <= end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}
