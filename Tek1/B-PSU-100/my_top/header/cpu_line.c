/*
** EPITECH PROJECT, 2024
** task line
** File description:
** displays the second line
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

void print_data_cpu(scan_cpu_t prev,
    scan_cpu_t cur, unsigned long total)
{
    cpu_data_t cpu_data = {0};

    cpu_data.user = ((cur.user - prev.user) / (float)total) * 100;
    cpu_data.nice = ((cur.nice - prev.nice) / (float)total) * 100;
    cpu_data.system = ((cur.system - prev.system) / (float)total) * 100;
    cpu_data.idle = ((cur.idle - prev.idle) / (float)total) * 100;
    cpu_data.iowait = ((cur.iowait - prev.iowait) / (float)total) * 100;
    cpu_data.irq = ((cur.irq - prev.irq) / (float)total) * 100;
    cpu_data.softirq = ((cur.softirq - prev.softirq) / (float)total) * 100;
    cpu_data.steal = ((cur.steal - prev.steal) / (float)total) * 100;
    mvprintw(2, 0,
            "%%Cpu(s): %.1f us, %.1f sy, %.1f ni, %.1f id, "
            "%.1f wa, %.1f hi, %.1f si, %.1f st",
            cpu_data.user, cpu_data.system, cpu_data.nice,
            cpu_data.idle, cpu_data.iowait, cpu_data.irq,
            cpu_data.softirq, cpu_data.steal);
}

void print_exception(scan_cpu_t cur, unsigned long total)
{
    cpu_data_t cpu_data = {0};

    cpu_data.user = (cur.user / (float)total) * 100;
    cpu_data.nice = (cur.nice / (float)total) * 100;
    cpu_data.system = (cur.system / (float)total) * 100;
    cpu_data.idle = (cur.idle / (float)total) * 100;
    cpu_data.iowait = (cur.iowait / (float)total) * 100;
    cpu_data.irq = (cur.irq / (float)total) * 100;
    cpu_data.softirq = (cur.softirq / (float)total) * 100;
    cpu_data.steal = (cur.steal / (float)total) * 100;
    mvprintw(2, 0,
            "%%Cpu(s): %.1f us, %.1f sy, %.1f ni, %.1f id, "
            "%.1f wa, %.1f hi, %.1f si, %.1f st",
            cpu_data.user, cpu_data.system, cpu_data.nice,
            cpu_data.idle, cpu_data.iowait, cpu_data.irq,
            cpu_data.softirq, cpu_data.steal);
}

void print_cpu_line(scan_cpu_t previous, scan_cpu_t current)
{
    unsigned long prev_total = previous.user +
        previous.nice + previous.system +
        previous.idle + previous.iowait + previous.irq +
        previous.softirq + previous.steal;
    unsigned long curr_total = current.user +
        current.nice + current.system +
        current.idle + current.iowait + current.irq +
        current.softirq + current.steal;
    unsigned long total_diff = curr_total - prev_total;

    if (total_diff == 0) {
        print_exception(current, curr_total);
        return;
    }
    print_data_cpu(previous, current, total_diff);
}

scan_cpu_t get_scancpu(void)
{
    scan_cpu_t scan_cpu = {0};
    FILE *file = fopen("/proc/stat", "r");

    if (!file)
        return scan_cpu;
    fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu", &scan_cpu.user,
    &scan_cpu.nice, &scan_cpu.system, &scan_cpu.idle, &scan_cpu.iowait,
    &scan_cpu.irq, &scan_cpu.softirq, &scan_cpu.steal);
    fclose(file);
    return scan_cpu;
}
