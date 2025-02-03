/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** sort_alphabetical
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
#include "ls_functions.h"

static void swap_node_alp(node_t *first_node, node_t *second_node)
{
    struct dirent *temp = first_node->entry;

    first_node->entry = second_node->entry;
    second_node->entry = temp;
}

static int cmp_and_swap_node_alp(node_t *first_node
    , node_t *second_node)
{
    if (my_strcmp(my_strlowcase(my_strdup(first_node->entry->d_name))
        , my_strlowcase(my_strdup(second_node->entry->d_name))) > 0) {
        swap_node_alp(first_node, second_node);
        return 1;
    }
    return 0;
}

int my_sort_nodes_alp(node_t **begin)
{
    int swapped;
    node_t *pointeur1;
    node_t *pointeur2 = NULL;

    if (*begin == NULL)
        return 0;
    do {
        swapped = 0;
        pointeur1 = *begin;
        while (pointeur1->next != pointeur2) {
            swapped |= cmp_and_swap_node_alp(pointeur1, pointeur1->next);
            pointeur1 = pointeur1->next;
        }
        pointeur2 = pointeur1;
    } while (swapped);
    return 0;
}

void swap_alp(dir_t *first_dir, dir_t *second_dir)
{
    node_t *temp = first_dir->node;
    char *path_temp = first_dir->path;

    first_dir->node = second_dir->node;
    second_dir->node = temp;
    first_dir->path = second_dir->path;
    second_dir->path = path_temp;
}

int cmp_and_swap_alp(dir_t *first_dir
    , dir_t *second_dir)
{
    if (my_strcmp(my_strlowcase(my_strdup(first_dir->path))
        , my_strlowcase(my_strdup(second_dir->path))) > 0) {
        swap_alp(first_dir, second_dir);
        return 1;
    }
    return 0;
}

int my_sort_list_alp(dir_t **begin)
{
    int swapped;
    dir_t *pointeur1;
    dir_t *pointeur2 = NULL;

    if (*begin == NULL)
        return 0;
    do {
        swapped = 0;
        pointeur1 = *begin;
        while (pointeur1->next != pointeur2) {
            swapped |= cmp_and_swap_alp(pointeur1, pointeur1->next);
            pointeur1 = pointeur1->next;
        }
        my_sort_nodes_alp(&(pointeur1->node));
        pointeur2 = pointeur1;
    } while (swapped);
    return 0;
}
