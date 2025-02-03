/*
** EPITECH PROJECT, 2024
** Organized
** File description:
** organized
*/

#include "organized.h"
#include "my.h"
#include <stdint.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <string.h>

static int compare_id_rev(hardware_t *first, hardware_t *second)
{
    return second->id - first->id;
}

static int compare_name_rev(hardware_t *first, hardware_t *second)
{
    return my_strcmp(second->name, first->name);
}

static int compare_type_rev(hardware_t *first, hardware_t *second)
{
    return my_strcmp(second->type, first->type);
}

hardware_t *merge(hardware_t *left, hardware_t *right,
    int (*compare)(hardware_t *, hardware_t *))
{
    hardware_t *result = NULL;

    if (!left)
        return right;
    if (!right)
        return left;
    if (compare(left, right) <= 0) {
        result = left;
        result->next = merge(left->next, right, compare);
    } else {
        result = right;
        result->next = merge(left, right->next, compare);
    }
    return result;
}

hardware_t *split(hardware_t *head)
{
    hardware_t *slow = head;
    hardware_t *fast = head->next;
    hardware_t *middle;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    middle = slow->next;
    slow->next = NULL;
    return middle;
}

hardware_t *apply_mergesort(hardware_t *head,
    int (*compare)(hardware_t *, hardware_t *))
{
    hardware_t *middle = NULL;
    hardware_t *left = NULL;
    hardware_t *right = NULL;

    if (!head || !head->next)
        return head;
    middle = split(head);
    left = apply_mergesort(head, compare);
    right = apply_mergesort(middle, compare);
    return merge(left, right, compare);
}

static int check_compare_functions(char **args)
{
    if (args[0] != NULL)
        if (my_strcmp(args[0], "-r") == 0)
            return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "ID") != 0 && my_strcmp(args[i], "TYPE") != 0
            && my_strcmp(args[i], "NAME") != 0
            && my_strcmp(args[i], "-r") != 0)
            return 84;
    }
    return 0;
}

static int (*rev_compare_function
    (int (*compare_func)(hardware_t *, hardware_t *)))
(hardware_t *, hardware_t *)
{
    if (compare_func == compare_id)
        return compare_id_rev;
    if (compare_func == compare_name)
        return compare_name_rev;
    return compare_type_rev;
}

void apply_flags(hardware_t **list_hardware, char **args, int num_args)
{
    int (*compare_func)(hardware_t *, hardware_t *) = NULL;
    int reverse = 0;

    for (int i = num_args - 1; i >= 0; i--) {
        if (my_strcmp(args[i], "-r") == 0) {
            reverse = 1;
            continue;
        }
        if (my_strcmp(args[i], "ID") == 0)
            compare_func = compare_id;
        if (my_strcmp(args[i], "NAME") == 0)
            compare_func = compare_name;
        if (my_strcmp(args[i], "TYPE") == 0)
            compare_func = compare_type;
        if (reverse == 1)
            compare_func = rev_compare_function(compare_func);
        *list_hardware = apply_mergesort(*list_hardware, compare_func);
        reverse = 0;
    }
}

int sort(void *data, char **args)
{
    hardware_t **list_hardware = (hardware_t **)data;
    int num_args = 0;

    if (check_compare_functions(args) == 84 || args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        num_args++;
    apply_flags(list_hardware, args, num_args);
    return 0;
}
