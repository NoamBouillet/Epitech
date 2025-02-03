/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** reverses the order of the list's elements
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include "my.h"
#include "structs.h"

static void my_rev_nodes(node_t **begin)
{
    node_t *last = NULL;
    node_t *actual_element = *begin;
    node_t *next = NULL;

    while (actual_element != NULL) {
        next = actual_element->next;
        actual_element->next = last;
        last = actual_element;
        actual_element = next;
    }
    *begin = last;
}

void my_rev_list(dir_t **begin)
{
    dir_t *last = NULL;
    dir_t *actual_element = *begin;
    dir_t *next = NULL;

    while (actual_element != NULL) {
        my_rev_nodes(&actual_element->node);
        next = actual_element->next;
        actual_element->next = last;
        last = actual_element;
        actual_element = next;
    }
    *begin = last;
}
