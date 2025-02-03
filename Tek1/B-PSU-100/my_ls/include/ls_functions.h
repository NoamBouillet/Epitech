/*
** EPITECH PROJECT, 2024
** ls_functions
** File description:
** ls_functions definition
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
#include <stdbool.h>

#ifndef LS_FUNCTIONS_H_
    #define LS_FUNCTIONS_H_

int search_for_flags(int, char **argv, flags_t *);
int my_ls(int argc, char **argv);
int sort_with_flags(flags_t flags, node_t *);
int create_list_dirs(int argc, char **argv, dir_t **dir_list, flags_t flags);
void *my_memcpy(void *dest, const void *src, size_t n);
int handle_file(const char *path, dir_t **dir_list);
int add_entry_to_tab(node_t **list_head, struct dirent *entry);
int handle_directory(const char *path, node_t **list_head, flags_t flags);
int process_directory(const char *dirname, dir_t **dir_list, flags_t flags);
int apply_flags(dir_t **dir, flags_t flags);
int handle_flags_and_print(flags_t flags, dir_t *dir_list);
void print_list(dir_t *dir_list, flags_t flags);
int dash_l(flags_t flags, dir_t *dir_list);
void free_list(dir_t *dir_list);
int read_directory_entries(DIR *dir, const char *path
    , dir_t **dir_list, flags_t flags);
node_t *create_node(const char *path, struct dirent *entry);
int copy_path(char *path, dir_t *dir_list, struct dirent *entry);
char *absolute_path(dir_t *dir, node_t *node);

//Chained lists (day11)

void my_rev_list(dir_t **begin);
int my_sort_list(dir_t **begin);
int delete_hidden(dir_t **begin);
int my_list_size(dir_t const *begin);
int print_permissions(char *real_path);
int my_list_size_nodes(node_t const *begin);
int my_sort_list_alp(dir_t **begin);
int my_list_size_nodes(node_t const *begin);

#endif
