/*
** EPITECH PROJECT, 2024
** time sort
** File description:
** sorts a list by time
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

static void swap_node(node_t *first_node, node_t *second_node)
{
    struct dirent *temp = first_node->entry;

    first_node->entry = second_node->entry;
    second_node->entry = temp;
}

static int cmp_and_swap_node(node_t *first_node
    , node_t *second_node, dir_t *current)
{
    struct stat path_stat;
    struct stat path_stat2;
    char *real_path1 = absolute_path(current, first_node);
    char *real_path2 = absolute_path(current, second_node);

    if (stat(real_path1, &path_stat) != 0)
        exit(84);
    if (stat(real_path2, &path_stat2) != 0)
        exit(84);
    if (path_stat.st_mtime < path_stat2.st_mtime) {
        swap_node(first_node, second_node);
        return 1;
    }
    return 0;
}

int my_sort_nodes(node_t **begin, dir_t *current)
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
            swapped |= cmp_and_swap_node(pointeur1, pointeur1->next
            , current);
            pointeur1 = pointeur1->next;
        }
        pointeur2 = pointeur1;
    } while (swapped);
    return 0;
}

void swap(dir_t *first_dir, dir_t *second_dir)
{
    struct dirent *temp = first_dir->node->entry;
    char *path_temp = first_dir->path;

    first_dir->node->entry = second_dir->node->entry;
    second_dir->node->entry = temp;
    first_dir->path = second_dir->path;
    second_dir->path = path_temp;
}

int cmp_and_swap(dir_t *first_dir
    , dir_t *second_dir)
{
    struct stat path_stat;
    struct stat path_stat2;
    char *real_path1 = first_dir->path;
    char *real_path2 = second_dir->path;

    if (stat(real_path1, &path_stat) != 0)
        exit(84);
    if (stat(real_path2, &path_stat2) != 0)
        exit(84);
    if (path_stat.st_mtime < path_stat2.st_mtime) {
        swap(first_dir, second_dir);
        return 1;
    }
    return 0;
}

int my_sort_list(dir_t **begin)
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
            swapped |= cmp_and_swap(pointeur1, pointeur1->next);
            my_sort_nodes(&(pointeur1->node), pointeur1);
            pointeur1 = pointeur1->next;
        }
        my_sort_nodes(&(pointeur1->node), pointeur1);
        pointeur2 = pointeur1;
    } while (swapped);
    return 0;
}
