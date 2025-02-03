/*
** EPITECH PROJECT, 2024
** general
** File description:
** initialize and runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

processes_t *create_process_node(processes_t process)
{
    processes_t *new_node = malloc(sizeof(processes_t));

    if (!new_node)
        return NULL;
    *new_node = process;
    new_node->next = NULL;
    return new_node;
}

void append_process(processes_t **head, processes_t process)
{
    processes_t *new_node = create_process_node(process);
    processes_t *current;

    if (!new_node)
        return;
    if (*head == NULL)
        *head = new_node;
    else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}

void free_processes_list(processes_t *head)
{
    processes_t *current = head;
    processes_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

static int is_pid_directory(const char *dir_name)
{
    while (*dir_name) {
        if (!isdigit(*dir_name)) {
            return 0;
        }
        dir_name++;
    }
    return 1;
}

static int is_directory(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) == -1)
        return 0;
    return S_ISDIR(path_stat.st_mode);
}

void generate_linked_processes(struct dirent *entry
    , DIR *dp, processes_t **head)
{
    char full_path[262];
    processes_t process;

    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") == 0
            || strcmp(entry->d_name, "..") == 0) {
            entry = readdir(dp);
            continue;
        }
        if (!is_pid_directory(entry->d_name)) {
            entry = readdir(dp);
            continue;
        }
        snprintf(full_path, sizeof(full_path), "/proc/%s", entry->d_name);
        if (is_directory(full_path)) {
            process = get_files_stats(entry->d_name);
            append_process(head, process);
        }
        entry = readdir(dp);
    }
}

processes_t *get_processes_list(void)
{
    processes_t *head = NULL;
    struct dirent *entry;
    DIR *dir = opendir("/proc");

    entry = readdir(dir);
    generate_linked_processes(entry, dir, &head);
    closedir(dir);
    return head;
}
