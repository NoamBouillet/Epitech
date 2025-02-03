/*
** EPITECH PROJECT, 2024
** my_params_to_array
** File description:
** stores the program's parameters into an array of structures
*/

#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *my_params =
        malloc(sizeof(struct info_param) * (ac + 1));

    for (int i = 0; i < ac; i++) {
        my_params[i].length = my_strlen(av[i]);
        my_params[i].str = av[i];
        my_params[i].copy = my_strdup(av[i]);
        my_params[i].word_array = my_str_to_word_array(av[i]);
    }
    my_params[ac].length = 0;
    my_params[ac].str = NULL;
    my_params[ac].copy = NULL;
    my_params[ac].word_array = NULL;
    return my_params;
}
