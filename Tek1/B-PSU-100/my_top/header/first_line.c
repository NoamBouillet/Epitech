/*
** EPITECH PROJECT, 2024
** first_line
** File description:
** displays the first line infos of the header
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"
#include <utmp.h>
#include <time.h>

static char *get_date(void)
{
    char *date = malloc(sizeof(char) * 9);
    time_t time_data;
    struct tm *current;

    if (!date)
        return "";
    time_data = time(NULL);
    current = localtime(&time_data);
    snprintf(date, 36, "%02d:%02d:%02d",
    current->tm_hour, current->tm_min, current->tm_sec);
    date[8] = '\0';
    return date;
}

static char *get_loadavg_from_buff(char *buffer)
{
    double loadavg[3];
    char *result = malloc(64);

    if (!result)
        return "";
    sscanf(buffer, "%lf %lf %lf", &loadavg[0], &loadavg[1], &loadavg[2]);
    snprintf(result, 64, "%.2f %.2f %.2f", loadavg[0],
            loadavg[1], loadavg[2]);
    return result;
}

char *my_getload_avg(void)
{
    int fd = open("/proc/loadavg", O_RDONLY);
    char *buffer = malloc(300);
    int size = 0;

    if (fd == -1 || !buffer)
        return "";
    size = read(fd, buffer, 300);
    close(fd);
    buffer[size] = '\0';
    return buffer;
}

int get_users(void)
{
    int fd = 0;
    struct utmp entry;
    int number_users = 0;

    fd = open("/var/run/utmp", O_RDONLY);
    if (fd == -1) {
        return 0;
    }
    while (read(fd, &entry, sizeof(struct utmp)) == sizeof(struct utmp)) {
        if (entry.ut_type == USER_PROCESS) {
            number_users++;
        }
    }
    close(fd);
    return number_users - 1;
}

char *format_time(long time)
{
    long days = time / 86400;
    long hours = (time % 86400) / 3600;
    long minutes = (time % 3600) / 60;
    char *all_time = malloc(50);

    if (!all_time)
        return "";
    if (days > 0) {
        if (hours > 0)
            snprintf(all_time, 50
            , "%ld days, %ld:%02ld", days, hours, minutes);
        else
            snprintf(all_time, 50, "%ld days, %ld min", days, minutes);
    } else if (hours > 0) {
        snprintf(all_time, 50, "%ld:%02ld", hours, minutes);
    } else {
        snprintf(all_time, 50, "%ld min", minutes);
    }
    return all_time;
}

double get_uptime(void)
{
    FILE *file = fopen("/proc/uptime", "r");
    double uptime_seconds;

    if (!file)
        return 0;
    fscanf(file, "%lf", &uptime_seconds);
    fclose(file);
    return uptime_seconds;
}

void print_first_line(void)
{
    char *time = format_time((long)get_uptime());
    char *loadavg = get_loadavg_from_buff(my_getload_avg());
    char *date = get_date();

    mvprintw(0, 0,
    "top - %s up %s, %d user, load average: %s",
    date, time, get_users(), loadavg);
    free(time);
    free(loadavg);
    free(date);
}
