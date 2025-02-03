/*
** EPITECH PROJECT, 2024
** my_concat_list
** File description:
** concatenates two lists
*/

#include <stdlib.h>
#include "my.h"
#include "structs.h"

void concat_list(dir_t **begin1, dir_t *begin2)
{
    dir_t *begin = *begin1;

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
