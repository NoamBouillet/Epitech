/*
** EPITECH PROJECT, 2024
** my_sort_list2
** File description:
** sorts a list
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

void swap(linked_list_t *first_data, linked_list_t *second_data)
{
    char *temp = first_data->data;

    first_data->data = second_data->data;
    second_data->data = temp;
}

int cmp_and_swap(linked_list_t *first_data
    , linked_list_t *second_data, int (*cmp)())
{
    if ((*cmp)(first_data->data, second_data->data) > 0) {
        swap(first_data, second_data);
        return 1;
    }
    return 0;
}

int my_sort_list(linked_list_t **begin, int (*cmp)())
{
    int swapped;
    linked_list_t *pointeur1;
    linked_list_t *pointeur2 = NULL;

    if (*begin == NULL)
        return 0;
    do {
        swapped = 0;
        pointeur1 = *begin;
        while (pointeur1->next != pointeur2) {
            swapped |= cmp_and_swap(pointeur1, pointeur1->next, cmp);
            pointeur1 = pointeur1->next;
        }
        pointeur2 = pointeur1;
    } while (swapped);
    return 0;
}
