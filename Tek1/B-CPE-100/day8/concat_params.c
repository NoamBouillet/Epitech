/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** puts arguments into a single string
*/
#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *concat_params(int argc, char **argv)
{
    int length = argc;
    char *str;

    for (int k = 0; k < argc; k++)
        length = length + my_strlen(argv[k]);
    str = malloc(sizeof(char) * (length + 1));
    for (int j = 0; j < argc; j++) {
        my_strcat(str, argv[j]);
        my_strcat(str, "\n");
    }
    str[length - 1] = '\0';
    return str;
}
