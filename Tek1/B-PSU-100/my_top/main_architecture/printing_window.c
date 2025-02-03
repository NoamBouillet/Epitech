/*
** EPITECH PROJECT, 2024
** main
** File description:
** runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"
#include <signal.h>

void print_head(processes_t *head, int nbr_process, flags_t flags)
{
    int x = 0;
    int y = 7;

    for (int i = 0; i < nbr_process && head != NULL; i++)
        head = head->next;
    while (head != NULL) {
        if (flags.U && (strncmp(head->user, flags.U_name, 7))) {
            head = head->next;
            continue;
        }
        mvprintw(y, x, "%7i %s %7s %3i %7s %6i %6i %c %5.1f %5.1f %9s %s"
            , head->PID, head->user, head->priority, head->nice
            , head->virt, head->resident, head->shared, head->state
            , head->cpu, head->mem, head->time, head->command);
        head = head->next;
        y++;
    }
}

void initialize_print(processes_t *head,
    scan_cpu_t previous, scan_cpu_t current)
{
    mvprintw(6, 0,
            "%7s%5s%8s%4s%8s%7s%7s%2s  %%CPU  %%MEM%10s COMMAND",
            "PID", "USER", "PR", "NI", "VIRT", "RES", "SHR", "S", "TIME+");
        head = get_processes_list();
    print_first_line();
    print_task_line(head);
    print_cpu_line(previous, current);
    print_mem_line();
    print_mem_swap();
}

static processes_t *kill_process(processes_t **head, int nbr_process)
{
    processes_t *tmp;
    processes_t *previous = NULL;
    processes_t *current = *head;

    for (int i = 0; i < nbr_process; i++) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        kill(current->PID, SIGTERM);
        if (previous == NULL)
            *head = current->next;
        else
            previous->next = current->next;
        tmp = current;
        current = current->next;
        free(tmp);
    }
    return *head;
}

processes_t *get_arrows_and_kill(int ch, int *nbr_process, processes_t **head)
{
    if (ch == KEY_DOWN)
        (*nbr_process)++;
    if (ch == KEY_UP && *nbr_process > 0)
        (*nbr_process)--;
    if (ch == 'k') {
        mvprintw(5, 0, "Sent a SIGTERM to the highest process in the list.");
        return kill_process(head, *nbr_process);
    }
    return *head;
}

void move_text(processes_t *head, flags_t flags)
{
    int ch;
    int nbr_process = 0;
    scan_cpu_t previous = get_scancpu();
    scan_cpu_t current;

    for (int iterations = 0; iterations != flags.n_iterations; iterations++) {
        current = get_scancpu();
        clear();
        initialize_print(head, previous, current);
        print_head(head, nbr_process, flags);
        ch = getch();
        if (ch == 'q')
            break;
        head = get_processes_list();
        head = get_arrows_and_kill(ch, &nbr_process, &head);
        refresh();
        previous = current;
    }
}

int create_window(flags_t flags)
{
    processes_t *head = get_processes_list();

    initscr();
    noecho();
    cbreak();
    timeout(flags.d_seconds * 1000);
    keypad(stdscr, TRUE);
    move_text(head, flags);
    endwin();
    return 0;
}
