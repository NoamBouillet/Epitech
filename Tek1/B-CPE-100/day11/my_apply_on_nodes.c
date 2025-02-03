/*
** EPITECH PROJECT, 2024
** my_apply_on_nodes
** File description:
** applies a function on nodes
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
