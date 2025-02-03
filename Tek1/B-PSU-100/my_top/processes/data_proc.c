/*
** EPITECH PROJECT, 2024
** main
** File description:
** runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

static char *format_ticks(long total_ticks)
{
    long total_seconds = total_ticks / HZ;
    long minutes = total_seconds / 60;
    long seconds = total_seconds % 60;
    long lower = (total_ticks % HZ) * 100 / HZ;
    char *time = malloc(32);

    if (!time)
        return "";
    snprintf(time, 32, "%01ld:%02ld.%02ld", minutes, seconds, lower);
    return time;
}

static long get_total_memory(void)
{
    FILE *file = fopen("/proc/meminfo", "r");
    long total_memory = 0;
    char line[256];

    if (!file)
        return 0;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1)
            break;
    }
    fclose(file);
    return total_memory;
}

static float get_mem_process(float resident)
{
    static long total_memory = 0;

    if (!total_memory)
        total_memory = get_total_memory();
    if (total_memory == 0 || resident == 0)
        return 0.0;
    return ((resident / total_memory) * 100.0 <= 0) ?
        (0.00) : (resident / total_memory) * 100.0;
}

static long get_time_process(char **fields)
{
    long utime = atol(fields[13]);
    long stime = atol(fields[14]);

    if (utime + stime < 0)
        return 0;
    return utime + stime;
}

char *absolute_path(char *filenumber)
{
    int total_length = strlen(filenumber) + 12;
    char *path = malloc(total_length);

    if (!path)
        return "";
    strcpy(path, "/proc");
    strcat(path, "/");
    strcat(path, filenumber);
    strcat(path, "/stat");
    return path;
}

processes_t parse_other_files(processes_t process
    , char *buffer, char *filename)
{
    char **fields = my_str_to_word_array(buffer);

    process.user = get_username(filename);
    process.mem = get_mem_process(process.resident);
    process.cpu = get_cpu_percentage(get_time_process(fields));
    process.time = format_ticks(get_time_process(fields));
    for (int i = 0; fields[i]; i++)
        free(fields[i]);
    free(fields);
    free(buffer);
    return process;
}

processes_t parse_stat_file(char *buffer, char *filename)
{
    processes_t process = {0};
    int i = get_added_words(buffer);
    char **fields = my_str_to_word_array(buffer);

    process.PID = atoi(fields[0]);
    process.priority = strdup(fields[17 + i]);
    if (!strcmp(process.priority, "100"))
        process.priority = "rt";
    process.nice = atoi(fields[18 + i]);
    process.state = fields[2 + i][0];
    process.virt = get_virt(filename);
    process.resident = atol(fields[23 + i]) * PAGE_SIZE / 1024;
    process.shared = atoi(get_shared(filename)) * 4;
    process.command = get_command_name(buffer);
    for (int i = 0; fields[i]; i++)
        free(fields[i]);
    free(fields);
    return process;
}

processes_t get_files_stats(char *filename)
{
    int fd;
    processes_t process;
    char *real_path = absolute_path(filename);
    int size;
    char *buffer = malloc(sizeof(char) * (400 + 1));

    fd = open(real_path, O_RDONLY);
    if (fd == -1 || !buffer){
        write(2, "Error, no valid proc given\n", 27);
        return (processes_t){0};
    }
    size = read(fd, buffer, 400);
    buffer[size] = '\0';
    close(fd);
    process = parse_stat_file(buffer, filename);
    free(real_path);
    return parse_other_files(process, buffer, filename);
}
