/*
** EPITECH PROJECT, 2024
** list_dirs_and_flags
** File description:
** create arrays of dirs and files
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
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>


node_t *create_node(const char *path, struct dirent *entry)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node) {
        write(2, "Memory allocation error for node\n", 33);
        return NULL;
    }
    new_node->path = my_strdup(path);
    new_node->entry = entry;
    new_node->next = NULL;
    return new_node;
}

dir_t *create_dir(const char *path)
{
    dir_t *new_dir = malloc(sizeof(dir_t));

    if (!new_dir) {
        write(2, "Memory allocation error for dir\n", 32);
        return NULL;
    }
    new_dir->path = my_strdup(path);
    new_dir->node = NULL;
    new_dir->next = NULL;
    return new_dir;
}

static int add_entry_to_dir(struct dirent *entry
    , const char *path, dir_t **dir)
{
    node_t *new_node = create_node(path, entry);

    if (!new_node)
        exit(84);
    new_node->next = (*dir)->node;
    (*dir)->node = new_node;
    return 0;
}

int read_directory_entries(DIR *dir, const char *path
    , dir_t **dir_list, flags_t flags)
{
    struct dirent *entry;
    dir_t *current_dir = create_dir(path);

    if (!current_dir)
        exit(84);
    current_dir->next = *dir_list;
    *dir_list = current_dir;
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] == '.' && flags.a == false) {
            entry = readdir(dir);
            continue;
        }
        if (add_entry_to_dir(entry, path, &current_dir) == 84)
                exit(84);
        entry = readdir(dir);
    }
    return 0;
}

int process_directory(const char *dirname, dir_t **dir_list, flags_t flags)
{
    DIR *dir = opendir(dirname);

    if (!dir) {
        write(2, "opendir() error\n", 16);
        exit(84);
    }
    if (read_directory_entries(dir, dirname, dir_list, flags) == 84) {
        closedir(dir);
        exit(84);
    }
    return 0;
}

static int handle_path(const char *path, dir_t **dir_list, flags_t flags)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        write(2, "Error accessing path\n", 22);
        exit(84);
    }
    if (S_ISDIR(path_stat.st_mode)) {
        return process_directory(path, dir_list, flags);
    } else if (S_ISREG(path_stat.st_mode)) {
        return handle_file(path, dir_list);
    }
    return 0;
}

int create_list_dirs(int argc, char **argv, dir_t **dir_list, flags_t flags)
{
    int has_path = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            continue;
        }
        if (handle_path(argv[i], dir_list, flags) == 84) {
            exit(84);
        }
        has_path = 1;
    }
    if (!has_path) {
        return handle_path(".", dir_list, flags);
    }
    return 0;
}
