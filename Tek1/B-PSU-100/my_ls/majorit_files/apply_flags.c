/*
** EPITECH PROJECT, 2024
** displays_normal
** File description:
** prints classical
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
#include <stdbool.h>
#include <unistd.h>

void free_list(dir_t *dir_list)
{
    dir_t *current_dir;
    node_t *node;
    node_t *temp;

    while (dir_list != NULL) {
        current_dir = dir_list;
        node = current_dir->node;
        while (node != NULL) {
            temp = node;
            node = node->next;
            free(temp->path);
            free(temp);
        }
        free(current_dir->path);
        dir_list = dir_list->next;
        free(current_dir);
    }
}

int print_dash_d(dir_t **current_dir, flags_t flags)
{
    if (flags.d == true) {
        my_printf("%s\n", (*current_dir)->path);
        *current_dir = (*current_dir)->next;
        return 0;
    }
    return -1;
}

static void print_directory(int size, node_t *current_node)
{
    if (size != 1 && current_node->path != NULL
        && current_node->next != NULL)
        my_printf("%s:\n", current_node->path);
}

void print_list(dir_t *dir_list, flags_t flags)
{
    dir_t *current_dir = dir_list;
    node_t *current_node;
    int size = my_list_size(current_dir);
    int i = 1;

    while (current_dir != NULL) {
        if (print_dash_d(&current_dir, flags) == 0)
            continue;
        current_node = current_dir->node;
        print_directory(size, current_node);
        while (current_node != NULL) {
            my_printf("%s\n", current_node->entry->d_name);
            current_node = current_node->next;
        }
        if (size != i)
            my_printf("\n");
        current_dir = current_dir->next;
        i++;
    }
}

int handle_flags_and_print(flags_t flags, dir_t *dir_list)
{
    print_list(dir_list, flags);
    free_list(dir_list);
    return 0;
}
