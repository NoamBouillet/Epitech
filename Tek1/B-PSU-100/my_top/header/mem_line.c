/*
** EPITECH PROJECT, 2024
** task line
** File description:
** displays the second line
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

void print_data_mem(unsigned long int mem_total, unsigned long
    int mem_free, unsigned long int buffcache, unsigned long int memavailable)
{
    float total = (float)mem_total / 1024;
    float free = (float)mem_free / 1024;
    float buff_cache = (float)(buffcache) / 1024.0;
    float used = total - ((float)memavailable / 1024);

    mvprintw(3, 0,
    "MiB Mem: %.1f total, %.1f free, %.1f used, %.1f buff/cache",
    total, free, used, buff_cache);
}

unsigned long int get_buffcache(FILE *file)
{
    char line[256];
    unsigned long int buff = 0;
    unsigned long int cache = 0;
    unsigned long int sreclaimable = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Buffers: %lu kB", &buff) == 1)
            continue;
        if (sscanf(line, "\nCached: %lu kB", &cache) == 1)
            continue;
        if (sscanf(line, "SReclaimable: %lu kB", &sreclaimable) == 1)
            continue;
    }
    return buff + cache + sreclaimable;
}

void print_mem_line(void)
{
    unsigned long int mem_total = 0;
    unsigned long int mem_free = 0;
    unsigned long int buffcache = 0;
    unsigned long int memavailable = 0;
    FILE *file = fopen("/proc/meminfo", "r");

    if (!file)
        return;
    fscanf(file, "MemTotal: %lu kB MemFree: %lu kB MemAvailable: %lu kB"
    , &mem_total, &mem_free, &memavailable);
    buffcache = get_buffcache(file);
    fclose(file);
    print_data_mem(mem_total, mem_free, buffcache, memavailable);
}
