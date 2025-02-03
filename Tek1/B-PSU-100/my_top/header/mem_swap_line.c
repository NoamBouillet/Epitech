/*
** EPITECH PROJECT, 2024
** task line
** File description:
** displays the second line
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

void print_data_swap(unsigned long int mem_total,
    unsigned long int mem_free, unsigned long int mem_available)
{
    float total = (float)mem_total / 1024;
    float free = (float)mem_free / 1024;
    float used = total - free;
    float available = (float)mem_available / 1024;

    mvprintw(4, 0,
    "MiB Swap: %.1f total, %.1f free, %.1f used. %.1f avail Mem",
    total, free, used, available);
}

void print_mem_swap(void)
{
    unsigned long int mem_total = 0;
    unsigned long int mem_free = 0;
    unsigned long int mem_available = 0;
    char line[256];
    FILE *file = fopen("/proc/meminfo", "r");

    if (!file)
        return;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "SwapTotal: %lu kB", &mem_total) == 1)
            continue;
        if (sscanf(line, "SwapFree: %lu kB", &mem_free) == 1)
            continue;
        if (sscanf(line, "MemAvailable: %lu kB", &mem_available) == 1)
            continue;
    }
    fclose(file);
    print_data_swap(mem_total, mem_free, mem_available);
}
