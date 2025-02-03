/*
** EPITECH PROJECT, 2024
** main
** File description:
** runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"
#include <utmp.h>

char *free_shared(char **fields, char *buffer)
{
    char *shared_value = strdup(fields[2]);

    for (int i = 0; fields[i]; i++)
        free(fields[i]);
    free(fields);
    free(buffer);
    return shared_value;
}

char *get_shared(char *filename)
{
    int fd;
    char **fields;
    int size = 0;
    char *buffer = malloc(sizeof(char) * (401));
    char *filestatus = malloc(sizeof(char) * 30);

    snprintf(filestatus, 30, "/proc/%s/statm", filename);
    fd = open(filestatus, O_RDONLY);
    if (fd == -1 || !filestatus || !buffer){
        write(2, "Error, no valid proc given\n", 27);
        return "";
    }
    size = read(fd, buffer, 400);
    buffer[size] = '\0';
    close(fd);
    fields = my_str_to_word_array(buffer);
    free(filestatus);
    return free_shared(fields, buffer);
}

float get_cpu_percentage(long combined_time)
{
    float clock_ticks_per_second = sysconf(_SC_CLK_TCK);
    float uptime = get_uptime();

    return ((combined_time / clock_ticks_per_second) / uptime) * 100;
}

FILE *get_file(char *name)
{
    FILE *file;

    file = fopen(name, "r");
    if (!(file))
        return NULL;
    return file;
}
