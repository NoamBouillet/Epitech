/*
** EPITECH PROJECT, 2024
** my_concat_list
** File description:
** concatenates two lists
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *begin = *begin1;

    if (begin1 == NULL)
        return;
    if (*begin1 == NULL) {
        *begin1 = begin2;
        return;
    }
    while (begin->next != NULL) {
        begin = begin->next;
    }
    begin->next = begin2;
}
