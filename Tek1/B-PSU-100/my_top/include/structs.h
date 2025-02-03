/*
** EPITECH PROJECT, 2024
** structs
** File description:
** my structs for files and flags
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <grp.h>
#include <stdbool.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct processes {
    int PID;
    char *user;
    char *priority;
    int nice;
    char *virt;
    int resident;
    int shared;
    char state;
    float cpu;
    float mem;
    char *time;
    char *command;
    struct processes *next;
} processes_t;

typedef struct flags {
    bool U;
    char *U_name;
    float d_seconds;
    bool n;
    int n_iterations;
    int problem;
} flags_t;

typedef struct tasks {
    int total;
    int running;
    int stopped;
    int zombie;
} tasks_t;

typedef struct get_data_cpu {
    unsigned long int user;
    unsigned long int system;
    unsigned long int nice;
    unsigned long int idle;
    unsigned long int iowait;
    unsigned long int irq;
    unsigned long int softirq;
    unsigned long int steal;
} scan_cpu_t;

typedef struct cpu {
    float user;
    float system;
    float nice;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
} cpu_data_t;

#endif
