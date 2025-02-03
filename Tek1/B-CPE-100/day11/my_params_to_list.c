/*
** EPITECH PROJECT, 2024
** my_params_to_list
** File description:
** creates a new list from the arguments given
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

static int my_node(linked_list_t **my_list, int ac, char *const *av)
{
    linked_list_t *element_of_list;

    for (int i = 0; i < ac; i++){
        element_of_list = malloc(sizeof(linked_list_t));
        element_of_list->data = av[i];
        element_of_list->next = *my_list;
        *my_list = element_of_list;
    }
    return 0;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *my_list_params;

    my_node(&my_list_params, ac, av);
    return my_list_params;
}
