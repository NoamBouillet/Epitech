/*
** EPITECH PROJECT, 2023
** solo stumper 1
** File description:
** countwords.h
*/

#ifndef COUNTWORDS_H
    #define COUNTWORDS_H
    #include <unistd.h>

typedef struct words {
    int number;
    char *value;
    struct words *next;
} words_t;

// LIB

char **my_str_to_word_array(char *str);
char *my_strdup(const char *str);
int my_strcmp(char *str, char *to_compare);
int my_strlen(char const *str);

#endif /* COUNTWORDS_H */
