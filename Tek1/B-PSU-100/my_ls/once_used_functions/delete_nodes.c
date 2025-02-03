/*
** EPITECH PROJECT, 2024
** my_delete_nodes
** File description:
** deletes a node
*/

#include <stdlib.h>
#include "my.h"
#include "structs.h"
#include <stdio.h>

static void my_normal_operation(node_t *actual, node_t *tmp)
{
    tmp = actual->next->next;
    free(actual->next);
    actual->next = tmp;
    return;
}

static void my_first_operation(node_t **actual, node_t *tmp,
    node_t **begin)
{
    tmp = (*actual)->next;
    free(*actual);
    *actual = tmp;
    *begin = *actual;
    return;
}

static int delete_node_hidden(node_t **begin)
{
    node_t *actual = *begin;
    node_t *tmp = NULL;

    while (actual->entry->d_name[0] == '.' && actual != NULL)
        my_first_operation(&actual, tmp, begin);
    while (actual->next != NULL && actual != NULL) {
        if (actual->next->next == NULL &&
            actual->next->entry->d_name[0] == '.'){
            free(actual->next);
            actual->next = NULL;
            break;
        }
        if (actual->next->entry->d_name[0] == '.')
            my_normal_operation(actual, tmp);
        actual = actual->next;
    }
    return 0;
}

int delete_hidden(dir_t **begin)
{
    dir_t *actual = *begin;

    while (actual != NULL) {
        delete_node_hidden(&actual->node);
        actual = actual->next;
    }
    return 0;
}
