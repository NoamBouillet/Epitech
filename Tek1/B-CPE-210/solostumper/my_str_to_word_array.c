/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <stddef.h>

int my_str_non_alphanumeric(char const *str, int i)
{
    char letter = 0;

    if (!(*str) || !str[i])
        return 84;
    letter = str[i];
    if (letter == '\t' || letter == ' ')
        return 1;
    return 0;
}

char *my_strncpy(char *dest, char const *src, int n, int k)
{
    for (int i = k; i < n; i++)
        dest[i - k] = src[i];
    dest[n - k] = '\0';
    return dest;
}

char *allocate_word(char const *str, int *i, int *k)
{
    char *word = malloc(sizeof(char) * ((*i) - (*k) + 1));

    if (!word)
        return "";
    return my_strncpy(word, str, *i, *k);
}

static int number_words(char const *str)
{
    int nbr = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (my_str_non_alphanumeric(str, i) == 1) {
            i++;
        }
        while (my_str_non_alphanumeric(str, i) == 0) {
            i++;
        }
        nbr++;
    }
    return nbr;
}

char **cuts_string(char const *str, char **array)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        while (my_str_non_alphanumeric(str, i) == 1 && str[i] != '\0') {
            i++;
            k++;
        }
        if (str[k] == '\0')
            break;
        while (my_str_non_alphanumeric(str, i) == 0 && str[i] != '\0')
            i++;
        array[j] = allocate_word(str, &i, &k);
        j++;
        k = i;
    }
    array[j] = NULL;
    return array;
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (number_words(str) + 1));

    if (!array || !str)
        return NULL;
    array = cuts_string(str, array);
    return array;
}
