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
#include <string.h>

static int read_directory(const char *path, node_t **list_head
    , struct dirent *entry, DIR *dir)
{
    node_t *new_node;

    if (entry->d_name[0] == '.')
        return 0;
    new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        exit(84);
    if (!new_node) {
        write(2, "Memory allocation error for node\n", 33);
        closedir(dir);
        exit(84);
    }
    new_node->entry = malloc(sizeof(struct dirent));
    if (new_node->entry == NULL)
        exit(84);
    my_memcpy(new_node->entry, entry, sizeof(struct dirent));
    new_node->path = my_strdup(path);
    new_node->next = *list_head;
    *list_head = new_node;
    return 0;
}

int initialize_node(dir_t *new_dir, struct dirent *entry
    , node_t *new_node, dir_t **dir_list)
{
    new_dir = malloc(sizeof(dir_t));
    if (!new_dir) {
        write(2, "Memory allocation error for dir\n", 32);
        free(entry);
        exit(84);
    }
    new_dir->path = my_strdup(".");
    new_dir->node = new_node;
    new_dir->next = *dir_list;
    *dir_list = new_dir;
    return 0;
}

int handle_file(const char *path, dir_t **dir_list)
{
    struct dirent *entry = malloc(sizeof(struct dirent));
    node_t *new_node;
    dir_t *new_dir;

    if (!entry) {
        write(2, "Memory allocation error for file entry\n", 39);
        exit(84);
    }
    my_strncpy(entry->d_name, path, sizeof(entry->d_name) - 1);
    entry->d_name[sizeof(entry->d_name) - 1] = '\0';
    new_node = create_node(path, entry);
    if (!new_node) {
        free(entry);
        exit(84);
    }
    if (initialize_node(new_dir, entry, new_node, dir_list) == 84)
        exit(84);
    return 0;
}
