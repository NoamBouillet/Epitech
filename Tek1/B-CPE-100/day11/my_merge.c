/*
** EPITECH PROJECT, 2024
** my_merge
** File description:
** concatenates two strings and sorts them
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

void my_merge(linked_list_t **begin, linked_list_t *begin2, int (*cmp)())
{
    if (begin == NULL) {
        return;
    }
    my_concat_list(begin, begin2);
    my_sort_list(begin, cmp);
}
