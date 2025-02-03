/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** returns the size of a list
*/

#include <stdlib.h>
#include "my.h"
#include "structs.h"

int my_list_size(dir_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return i;
}

int my_list_size_nodes(node_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return i;
}
