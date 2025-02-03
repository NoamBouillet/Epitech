/*
** EPITECH PROJECT, 2024
** task line
** File description:
** displays the second line
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

tasks_t collect_data_tasks(processes_t *head)
{
    tasks_t tasks = {0};

    while (head != NULL) {
        tasks.total++;
        switch (head->state) {
            case 'R':
                tasks.running++;
                break;
            case 'Z':
                tasks.zombie++;
                break;
            case 'T':
                tasks.stopped++;
                break;
        }
        head = head->next;
    }
    return tasks;
}

void print_task_line(processes_t *head)
{
    tasks_t tasks = collect_data_tasks(head);

    mvprintw(1, 0,
        "Tasks: %d total, %d running, %d sleeping, %d stopped, %d zombie",
        tasks.total, tasks.running, tasks.total - (tasks.running +
        tasks.stopped + tasks.zombie), tasks.stopped, tasks.zombie);
}
