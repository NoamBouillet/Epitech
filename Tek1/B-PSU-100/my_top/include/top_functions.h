/*
** EPITECH PROJECT, 2024
** top_functions
** File description:
** top_functions definition
*/

#include "my.h"

#ifndef TOP_FUNCTIONS_H_
    #define TOP_FUNCTIONS_H_

int search_for_flags(int, char **argv, flags_t *);
void *my_memcpy(void *dest, const void *src, int n);
void free_list(processes_t *dir_list);

//Chained lists (day11)

int my_sort_list(processes_t **begin);
int delete_from_list(processes_t **begin);
void free_processes_list(processes_t *head);
int my_list_size(processes_t const *begin);
int my_sort_list(processes_t **begin);
int get_added_words(char *buffer);
void print_first_line(void);
char *my_getload_avg(void);
void print_task_line(processes_t *head);
char *format_time(long time);
int get_users(void);
double get_uptime(void);
tasks_t collect_data_tasks(processes_t *head);
void print_cpu_line(scan_cpu_t previous, scan_cpu_t current);
void print_mem_line(void);
void print_mem_swap(void);
char *get_virt(char *filename);
char *get_shared(char *filename);
scan_cpu_t get_scancpu(void);
char *get_username(char *filename);
float get_cpu_percentage(long combined_time);
FILE *get_file(char *name);
processes_t *get_processes_list(void);
char *get_command_name(char *buffer);
int create_window(flags_t flags);
#endif
