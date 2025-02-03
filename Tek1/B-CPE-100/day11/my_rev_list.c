/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** reverses the order of the list's elements
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *last = NULL;
    linked_list_t *actual_element = *begin;
    linked_list_t *next = NULL;

    while (actual_element != NULL) {
        next = actual_element->next;
        actual_element->next = last;
        last = actual_element;
        actual_element = next;
    }
    *begin = last;
}
