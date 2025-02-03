/*
** EPITECH PROJECT, 2025
** count_words
** File description:
** main
*/

#include <stdio.h>
#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>

void append_to_words(words_t **words, words_t *last_word, words_t *new_word)
{
    if (!last_word)
        *words = new_word;
    else
        last_word->next = new_word;
}

int add_word(words_t **words, char *str)
{
    words_t *list_words = *words;
    words_t *new_word = NULL;
    words_t *last_word = NULL;

    for (; list_words != NULL; list_words = list_words->next) {
        if (my_strcmp(list_words->value, str) == 0) {
            list_words->number++;
            return 0;
        }
        last_word = list_words;
    }
    new_word = malloc(sizeof(words_t));
    if (!new_word)
        return 84;
    new_word->value = my_strdup(str);
    new_word->number = 1;
    new_word->next = NULL;
    append_to_words(words, last_word, new_word);
    return 0;
}

int count_words(char *string)
{
    char **cut_string = my_str_to_word_array(string);
    words_t *words = NULL;
    words_t *to_delete = NULL;

    for (int i = 0; cut_string[i] != NULL; i++) {
        if (add_word(&words, cut_string[i]) == 84)
            return 84;
        free(cut_string[i]);
    }
    for (; words != NULL; words = to_delete) {
        to_delete = words->next;
        printf("%s: %d\n", words->value, words->number);
        free(words->value);
        free(words);
    }
    free(cut_string);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (argc == 1) {
        printf("\n");
        return 0;
    }
    return count_words(argv[1]);
}
