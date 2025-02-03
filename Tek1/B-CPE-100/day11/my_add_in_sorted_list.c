/*
** EPITECH PROJECT, 2024
** my_add_in_sorted_list
** File description:
** add a struct into a list, and it stays sorted
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *new_struct = malloc(sizeof(linked_list_t));
    linked_list_t *advance = *begin;

    new_struct->data = data;
    new_struct->next = NULL;
    while (advance->next != NULL && advance != NULL)
        advance = advance->next;
    advance->next = new_struct;
    my_sort_list(begin, cmp);
}
