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

typedef struct node {
    struct dirent *entry;
    char *path;
    struct node *next;
} node_t;

typedef struct dir {
    node_t *node;
    char *path;
    struct dir *next;
} dir_t;

typedef struct permissions {
    int permission;
    void (*function)(void);
} permissions_t;

typedef struct flags {
    bool r;
    bool R;
    bool l;
    bool a;
    bool d;
    bool t;
    int problem;
} flags_t;

#endif
