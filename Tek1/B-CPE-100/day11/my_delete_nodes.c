/*
** EPITECH PROJECT, 2024
** my_delete_nodes
** File description:
** deletes a node
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

void my_normal_operation(linked_list_t *actual, linked_list_t *tmp)
{
    tmp = actual->next->next;
    free(actual->next);
    actual->next = tmp;
    return;
}

void my_first_operation(linked_list_t **actual, linked_list_t *tmp,
    linked_list_t **begin)
{
    tmp = (*actual)->next;
    free(*actual);
    *actual = tmp;
    *begin = *actual;
    return;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *actual = *begin;
    linked_list_t *tmp = NULL;

    while ((*cmp)(actual->data, data_ref) == 0 && actual != NULL)
        my_first_operation(&actual, tmp, begin);
    while (actual->next != NULL && actual != NULL) {
        if (actual->next->next == NULL &&
            (*cmp)(actual->next->data, data_ref) == 0){
            free(actual->next);
            actual->next = NULL;
            break;
        }
        if ((*cmp)(actual->next->data, data_ref) == 0)
            my_normal_operation(actual, tmp);
        actual = actual->next;
    }
    return 0;
}
