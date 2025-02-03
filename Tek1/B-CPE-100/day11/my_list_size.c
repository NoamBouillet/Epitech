/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** returns the size of a list
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return i;
}
