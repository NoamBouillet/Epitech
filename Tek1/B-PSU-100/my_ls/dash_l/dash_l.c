/*
** EPITECH PROJECT, 2024
** dash_l
** File description:
** prints everything for dash l
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
#include <pwd.h>
#include <unistd.h>
#include <linux/limits.h>

char *absolute_path(dir_t *dir, node_t *node)
{
    size_t total_length = my_strlen(dir->path)
        + my_strlen(node->entry->d_name) + 2;
    char *path = malloc(total_length);

    my_strcpy(path, dir->path);
    my_strcat(path, "/");
    my_strcat(path, node->entry->d_name);
    return path;
}

int print_symlink(node_t *node)
{
    char target_path[_PC_PATH_MAX];
    ssize_t len = readlink(node->entry->d_name
        , target_path, sizeof(target_path) - 1);

    if (len == -1) {
        exit(84);
    }
    target_path[len] = '\0';
    my_printf("%s -> %s\n", node->entry->d_name, target_path);
    return 0;
}

int print_file_type(const struct stat *path_stat)
{
    if (S_ISDIR(path_stat->st_mode))
        my_printf("d");
    if (S_ISREG(path_stat->st_mode))
        my_printf("-");
    if (S_ISLNK(path_stat->st_mode))
        my_printf("l");
    if (S_ISCHR(path_stat->st_mode))
        my_printf("c");
    return 0;
}

static int print_time(node_t *node, char **real_path)
{
    struct stat path_stat;
    char *time_str;

    if (lstat(*real_path, &path_stat) != 0)
        return 84;
    time_str = ctime(&path_stat.st_mtime);
    my_printf("%.12s ", time_str + 4);
    if (S_ISLNK(path_stat.st_mode)) {
        return print_symlink(node);
    }
    my_printf("%s\n", node->entry->d_name);
    free(*real_path);
    return 0;
}

static int print_uid(node_t *node, char **real_path)
{
    struct stat path_stat;
    struct passwd *pwd;
    struct group *grp;

    if (lstat(*real_path, &path_stat) != 0) {
        write(2, "Error accessing path uid\n", 25);
        exit(84);
    }
    pwd = getpwuid(path_stat.st_uid);
    if (pwd)
        my_printf("%s ", pwd->pw_name);
    grp = getgrgid(path_stat.st_gid);
    if (grp)
        my_printf("%s ", grp->gr_name);
    my_printf("%lu ", path_stat.st_size);
    return print_time(node, real_path);
}

static int print_typ_prm_lnk(node_t *node, dir_t *dir_list)
{
    struct stat path_stat;
    char *real_path = absolute_path(dir_list, node);

    if (lstat(real_path, &path_stat) != 0) {
        write(2, "Error accessing path typ_prm\n", 29);
        free(real_path);
        exit(84);
    }
    print_file_type(&path_stat);
    print_permissions(real_path);
    my_printf(" %d ", path_stat.st_nlink);
    return print_uid(node, &real_path);
}

static int print_all_dash_l(node_t *node, dir_t *dir_list)
{
    return print_typ_prm_lnk(node, dir_list);
}

static int print_total_blocks(dir_t *dir_list, flags_t flags)
{
    struct stat path_stat;
    DIR *dir = opendir(dir_list->path);
    int total_blocks = 0;
    char path[PATH_MAX];
    struct dirent *entry = readdir(dir);

    while (entry != NULL) {
        if (flags.a == false && entry->d_name[0] == '.') {
            entry = readdir(dir);
            continue;
        }
        copy_path(path, dir_list, entry);
        if (lstat(path, &path_stat) == 0)
            total_blocks += path_stat.st_blocks / 2;
        entry = readdir(dir);
    }
    closedir(dir);
    my_printf("total %d\n", total_blocks);
    return 0;
}

void print_dash_l(dir_t *dir_list, flags_t flags)
{
    dir_t *current_dir = dir_list;
    node_t *current_node;
    int size = my_list_size(current_dir);
    int i = 1;

    while (current_dir != NULL) {
        current_node = current_dir->node;
        if (size != 1 && my_list_size_nodes(current_node) != 1)
            my_printf("%s:\n", current_node->path);
        if (my_list_size_nodes(current_dir->node) != 1)
            print_total_blocks(dir_list, flags);
        while (current_node != NULL) {
            print_all_dash_l(current_node, current_dir);
            current_node = current_node->next;
        }
        if (size != i)
            my_printf("\n");
        current_dir = current_dir->next;
        i++;
    }
}

int dash_l(flags_t flags, dir_t *dir_list)
{
    print_dash_l(dir_list, flags);
    free_list(dir_list);
    return 0;
}
